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
# addresses.hpp

Contains RakNet function offsets and declaration of the "Addresses" class for accesing SA-MP internal structs.
*/

#include "types.hpp"

#ifndef SAMP_COMPAT_ADDRESSES_H
#define SAMP_COMPAT_ADDRESSES_H

#ifdef _WIN32
	#define RAKNET_START_OFFSET							1
	#define RAKNET_SEND_OFFSET							7
	#define RAKNET_RECEIVE_OFFSET						10
	#define RAKNET_SET_ALLOWED_PLAYERS_OFFSET			13
	#define RAKNET_GET_LAST_PING_OFFSET					19
	#define RAKNET_REGISTER_RPC_OFFSET					29
	#define RAKNET_UNREGISTER_RPC_OFFSET				31
	#define RAKNET_RPC_OFFSET							32
	#define RAKNET_GET_LOCAL_IP_OFFSET					52
	#define RAKNET_GET_INDEX_FROM_PLAYERID_OFFSET		57
	#define RAKNET_GET_PLAYERID_FROM_INDEX_OFFSET		58
	#define RAKNET_ADD_BAN_OFFSET						60
	#define RAKNET_REMOVE_BAN_OFFSET					61
	#define RAKNET_CLEAR_BAN_OFFSET						62
	#define RAKNET_SET_TIMEOUT_OFFSET					65
#else
	#define RAKNET_START_OFFSET							2
	#define RAKNET_SEND_OFFSET							9
	#define RAKNET_RECEIVE_OFFSET						11
	#define RAKNET_SET_ALLOWED_PLAYERS_OFFSET			14
	#define RAKNET_GET_LAST_PING_OFFSET					20
	#define RAKNET_REGISTER_RPC_OFFSET					30
	#define RAKNET_UNREGISTER_RPC_OFFSET				32
	#define RAKNET_RPC_OFFSET							35
	#define RAKNET_GET_LOCAL_IP_OFFSET					53
	#define RAKNET_GET_INDEX_FROM_PLAYERID_OFFSET		58
	#define RAKNET_GET_PLAYERID_FROM_INDEX_OFFSET		59
	#define RAKNET_ADD_BAN_OFFSET						61
	#define RAKNET_REMOVE_BAN_OFFSET					62
	#define RAKNET_CLEAR_BAN_OFFSET						63
	#define RAKNET_SET_TIMEOUT_OFFSET					65
#endif // _WIN32

enum SAMPVersion
{
	VERSION_UNKNOWN,
	VERSION_037_R2,
	VERSION_03DL_R1
};

class Addresses
{
public:
	static void Initialize();

	static DWORD FUNC_Logprintf_037_R2;
	static DWORD FUNC_Logprintf_03DL_R1;

	static DWORD FUNC_ClientJoin;
};

#endif // SAMP_COMPAT_ADDRESSES_H