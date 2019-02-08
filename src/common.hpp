/*
# common.hpp

Contains common variables used around the plugin
*/

#include "addresses.hpp"

#define MAX_PLAYERS 1000

extern void** ppPluginData;
extern void* pAMXFunctions;
typedef void (*logprintf_t)(const char* szFormat, ...);
extern logprintf_t logprintf;
extern void* pRakServer;

extern bool Initialized;

extern bool PlayerCompat[MAX_PLAYERS];
extern int currentVersion;
extern int iNetVersion;
extern int iCompatVersion;
extern char szVersion[64];
