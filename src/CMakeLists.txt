include(AMXConfig)
include(AddSAMPPlugin)

set(SAMP_SDK_ROOT "${PROJECT_SOURCE_DIR}/lib/samp-plugin-sdk")
set(SUBHOOK_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/subhook")
set(RAKNET_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/raknet")
find_package(SAMPSDK REQUIRED)

include_directories(
	${SAMPSDK_INCLUDE_DIR}
	${SUBHOOK_INCLUDE_DIR}
	${RAKNET_INCLUDE_DIR}
)

add_definitions(-DSUBHOOK_IMPLEMENTATION)

add_samp_plugin(samp-compat
	${SAMPSDK_DIR}/amxplugin.cpp
	${SAMPSDK_DIR}/amx/getch.c
	${SUBHOOK_INCLUDE_DIR}/subhook.c
	${RAKNET_INCLUDE_DIR}/BitStream.cpp
	common.hpp
	main.cpp
	impl.cpp
	natives.cpp
	addresses.cpp
	plugin.def
)

if(UNIX)
target_link_libraries(samp-compat -static-libgcc -static-libstdc++)
endif()
