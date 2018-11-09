/*
# main.cpp

The "main" source file with most of the boilerplate code. Includes the
`NativesMain` header for initialising plugin-natives.

- `Supports` declares to the SA:MP server which features this plugin uses.
- `Load` is called when the plugin loads and sets up the `logprintf` function.
*/

#include <amx/amx.h>
#include <plugincommon.h>
#include <string.h>

#include "common.hpp"
#include "natives.hpp"
#include "addresses.hpp"
#include "impl.hpp"

logprintf_t logprintf;

void** ppPluginData = NULL;
CNetGame* pNetGame = NULL;
void* pRakServer = NULL;

bool Initialized = false;
bool PostInitialized = false;

int iNetVersion;
int iCompatVersion;
char szVersion[64] = "Unknown";

bool PlayerCompat[MAX_PLAYERS] = { 0 };
int currentVersion = SAMPVersion::VERSION_UNKNOWN;

extern "C"
{
	AMX_NATIVE_INFO nativeList[] = {
	{ "IsPlayerCompat", Natives::IsPlayerCompat},
	{ 0, 0 }
	};
}

void Initialize()
{
	switch (currentVersion)
	{
		case SAMPVersion::VERSION_037_R2:
		{
			iNetVersion = 4057;
			iCompatVersion = 4062;
			strcpy(szVersion, "0.3.7-R2");
			break;
		}
		case SAMPVersion::VERSION_03DL_R1:
		{
			iNetVersion = 4062;
			iCompatVersion = 4057;
			strcpy(szVersion, "0.3.DL-R1");
			break;
		}
	}

	Addresses::Initialize();
	Impl::InstallPreHooks();

	logprintf("  -- samp-compat for %s initialized", szVersion);
	Initialized = true;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
	ppPluginData = ppData;
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];

	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	DWORD addr = reinterpret_cast<DWORD>(logprintf);
	
	if (addr == Addresses::FUNC_Logprintf_037_R2)
	{
		currentVersion = SAMPVersion::VERSION_037_R2;
		Initialize();
	}
	else if (addr == Addresses::FUNC_Logprintf_03DL_R1)
	{
		currentVersion = SAMPVersion::VERSION_03DL_R1;
		Initialize();
	}
	else
	{
		logprintf("  -- samp-compat: Unsupported version", szVersion);
		return false;
	}

    return true;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
	if (!PostInitialized)
	{
		// Get pNetGame
		int(*pfn_GetNetGame)(void) = (int(*)(void))ppPluginData[PLUGIN_DATA_NETGAME];
		pNetGame = (CNetGame*)pfn_GetNetGame();


		// Get pRakServer
		int(*pfn_GetRakServer)(void) = (int(*)(void))ppPluginData[PLUGIN_DATA_RAKSERVER];
		pRakServer = (void*)pfn_GetRakServer();

		Impl::InstallPostHooks();

		PostInitialized = true;
	}
    return amx_Register(amx, nativeList, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL Unload()
{
	if (Initialized)
	{
		Impl::UninstallHooks();
	}
    return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
    return 1;
}
