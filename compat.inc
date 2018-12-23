// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_compat
	#undef _inc_compat
#endif
// custom include-guard to ensure we don't duplicate
#if defined _compat_included
	#endinput
#endif
#define _compat_included

// Check if player is under compatibility mode
native IsPlayerCompat(playerid);
