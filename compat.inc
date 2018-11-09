// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_PAWN_INCLUDE
	#undef _inc_PAWN_INCLUDE
#endif
// custom include-guard to ensure we don't duplicate
#if defined _PAWN_INCLUDE_included
	#endinput
#endif
#define _PAWN_INCLUDE_included


// don't forget to change the above include guard to match the file name!

native Function();
