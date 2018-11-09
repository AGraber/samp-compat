/*
*  Version: MPL 1.1
*
*  The contents of this file are subject to the Mozilla Public License Version
*  1.1 (the "License"); you may not use this file except in compliance with
*  the License. You may obtain a copy of the License at
*  http://www.mozilla.org/MPL/
*
*  Software distributed under the License is distributed on an "AS IS" basis,
*  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
*  for the specific language governing rights and limitations under the
*  License.
*
*  The Original Code is the YSI 2.0 SA:MP plugin.
*
*  The Initial Developer of the Original Code is Alex "Y_Less" Cole.
*  Portions created by the Initial Developer are Copyright (C) 2008
*  the Initial Developer. All Rights Reserved. The development was abandobed
*  around 2010, afterwards kurta999 has continued it.
*
*  Contributor(s):
*
*	0x688, balika011, Gamer_Z, iFarbod, karimcambridge, Mellnik, P3ti, Riddick94
*	Slice, sprtik, uint32, Whitetigerswt, Y_Less, ziggi and complete SA-MP community
*
*  Special Thanks to:
*
*	SA:MP Team past, present and future
*	Incognito, maddinat0r, OrMisicL, Zeex
*
------------------
# structs.hpp

Minimal SA-MP structs and definitions for accesing some variables
*/

#ifndef SAMP_COMPAT_STRUCTS_H
#define SAMP_COMPAT_STRUCTS_H

#include "types.hpp"

#define MAX_PLAYERS (1000)

#pragma pack(push, 1)
struct CPlayerPool
{
	DWORD dwVirtualWorld[MAX_PLAYERS]; // 0 - 4000
	DWORD dwPlayersCount;
	char pad1[MAX_PLAYERS];
	DWORD dwlastMarkerUpdate;
	float fUpdatePlayerGameTimers;
	DWORD dwScore[MAX_PLAYERS];
	DWORD dwMoney[MAX_PLAYERS];
	DWORD dwDrunkLevel[MAX_PLAYERS];
	DWORD dwLastScoreUpdate[MAX_PLAYERS];
	char szSerial[MAX_PLAYERS][101];
	char szVersion[MAX_PLAYERS][25];
	void *pRemoteSystem[MAX_PLAYERS];
	BOOL bIsPlayerConnected[MAX_PLAYERS]; // I only added the other fields because I wanted to have this
};

struct CNetGame
{
	void		*pGameModePool;		// 0
	void		*pFilterScriptPool;	// 4
	CPlayerPool	*pPlayerPool;		// 8
};
#pragma pack(pop)

#endif // SAMP_COMPAT_STRUCTS_H