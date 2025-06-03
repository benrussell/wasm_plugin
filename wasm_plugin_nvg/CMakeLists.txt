
# This needs to be before project()
set(CMAKE_TOOLCHAIN_FILE $ENV{WASI_SDK_PATH}/share/cmake/wasi-sdk.cmake)


cmake_minimum_required(VERSION 3.13)
project(wasm_plugin_nvg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(INC_HOST_API ${CMAKE_SOURCE_DIR}/../host_api)

set(INC_NVG third_party/nanovg-master/src/)


include_directories(
        ${INC_HOST_API}
		${INC_NVG}
        )



set(EXPORTED_FUNCTIONS
	plugin_start
	plugin_stop
	plugin_enable
	plugin_disable
	plugin_message
	plugin_flcb_proxy
	malloc
	free
)

# Create linker flags from export list
set(EXPORT_FLAGS "")
foreach(fn IN LISTS EXPORTED_FUNCTIONS)
	string(APPEND EXPORT_FLAGS "-Wl,--export=${fn} ")
endforeach()

#set(EXPORT_FLAGS "${EXPORT_FLAGS}-Wl,--allow-undefined")
set(EXPORT_FLAGS "${EXPORT_FLAGS} -Wl,--no-entry")





set( SRC_FILES 
	wasm_plugin_nvg.cpp   wasm_plugin_nvg.h
	nanovg.c  nanovg.h
)




add_executable(wasm_plugin_nvg.wasm ${SRC_FILES})

set_target_properties(wasm_plugin_nvg.wasm PROPERTIES
	LINK_FLAGS "${EXPORT_FLAGS} -Wl,--export-table"
)
