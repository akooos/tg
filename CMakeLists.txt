cmake_minimum_required(VERSION 2.8)

project (tg)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
CHECK_CXX_COMPILER_FLAG("-ggdb" COMPILER_SUPPORTS_GGDB)

if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
	message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

if(COMPILER_SUPPORTS_GGDB)
#Here set debug c++ flags.
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb -O0 ")	
else()
	message("Can not generate debug symbols. Please use different C++ compiler.")
endif()
#Here set release c++ flags.
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 ")

set (TG_VERSION_MAJOR 0)
set (TG_VERSION_MINOR 1)

option(UseBoost "UseBoost" ON)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message(" >> Debug build. << ")
    
    set(bindir ${CMAKE_BINARY_DIR}/bin/debug)
    set(libdir ${CMAKE_BINARY_DIR}/lib/debug)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    message(">> Release build. <<")
    set(bindir ${CMAKE_BINARY_DIR}/bin/release)
    set(libdir ${CMAKE_BINARY_DIR}/lib/release)
else()
    message("-- No given build type. Debug build. --")
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
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
     # using Clang
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
     # using GCC
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
     # using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
   # using Visual Studio C++
endif()

if(UseBoost)
    find_package( Boost COMPONENTS locale REQUIRED )
    if ( Boost_FOUND )
        message(">> Using BOOST Library! <<")
        set(INCLUDE_DIRS "${INCLUDE_DIRS}  ${Boost_INCLUDE_DIR}" )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSING_BOOST")
        set(LIBS "${LIBS} ${Boost_LIBRARIES}")
    endif()
endif()
set(INCLUDE_DIRS "${INCLUDE_DIRS}  ./include " )
include_directories(tg PUBLIC ${INCLUDE_DIRS} )
add_subdirectory(src)

