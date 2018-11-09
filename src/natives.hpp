/*
# natives.hpp

Contains all the `PAWN_NATIVE_DECL` for native function declarations.
*/

#ifndef SAMP_COMPAT_NATIVES_H
#define SAMP_COMPAT_NATIVES_H

#include <string>

#include <amx/amx.h>

#include "common.hpp"

namespace Natives {
cell IsPlayerCompat(AMX* amx, cell* params);
}

#endif
