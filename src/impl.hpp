/*
# impl.hpp

From here on, it's just regular C++ code, no AMX/Pawn/SA:MP stuff. This header
is for declaring implementation functions for the plugin's core functionality.
*/

#ifndef SAMP_COMPAT_IMPL_H
#define SAMP_COMPAT_IMPL_H

namespace Impl {
	void InstallPreHooks();

	void InstallPostHooks();

	void UninstallHooks();

	bool IsPlayerCompat(int playerid);
};

#endif
