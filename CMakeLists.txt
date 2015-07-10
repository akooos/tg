cmake_minimum_required (VERSION 2.8)

project (tg)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set (TG_VERSION_MAJOR 0)
set (TG_VERSION_MINOR 1)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message("Debug build.")
    set(bindir ${CMAKE_BINARY_DIR}/bin/debug)
    set(libdir ${CMAKE_BINARY_DIR}/lib/debug)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    message("Release build.")
    set(bindir ${CMAKE_BINARY_DIR}/bin/release)
    set(libdir ${CMAKE_BINARY_DIR}/lib/release)
else()
    message("No given build type. Debug build.")
    set(bindir ${CMAKE_BINARY_DIR}/bin/debug)
    set(libdir ${CMAKE_BINARY_DIR}/lib/debug)
endif()


set(EXECUTABLE_OUTPUT_PATH ${bindir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${libdir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${bindir})
set(CMAKE_BUILD_FILES_DIRECTORY ${bindir})
set(CMAKE_BUILD_DIRECTORY ${bindir})
set(CMAKE_BINARY_DIR  ${bindir})
SET(EXECUTABLE_OUTPUT_PATH ${bindir})
SET(LIBRARY_OUTPUT_PATH ${libdir})
SET(CMAKE_CACHEFILE_DIR ${bindir})

configure_file ( "src/tg_config.h.in"
                 "src/tg_config.h"
               )

add_subdirectory(src)

target_include_directories(tg PUBLIC include)

