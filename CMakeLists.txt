#  :copyright: (c) 2017 Alex Huszagh.
#  :license: FreeBSD, see LICENSE.txt for more details.

set(CMAKE_LEGACY_CYGWIN_WIN32 1)
cmake_minimum_required(VERSION 2.8)
project(xlsxwriter++ CXX)
enable_testing()

# OPTIONS
# -------

option(BUILD_STATIC "Build static libxlsxwriter" ON)

# FLAGS
# -----

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# OPTIONS
# -------

if(BUILD_STATIC)
    if(UNIX)
        set(CMAKE_POSITION_INDEPENDENT_CODE ON)
    elseif(MINGW OR MSYS)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static -static-libgcc -Wno-char-subscripts -Wno-long-long")
        add_definitions(-DUSE_FILE32API)
    elseif(MSVC)
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /O0 /Fd${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pdb")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT /Ox /Zi /Fd${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pdb")
        set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /MT /Zi /Fd${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pdb")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT /Fd${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pdb")
    endif()
endif()

# Need to manually set compiler flags for Travis CI
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++11")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

# LIBRARY
# -------

set(LXWPP_SOURCES
    src/chart.cpp
    src/format.cpp
    src/utility.cpp
    src/workbook.cpp
    src/worksheet.cpp
)

enable_language(C)
add_subdirectory(libxlsxwriter)
include_directories(include libxlsxwriter/include)

if(BUILD_STATIC)
    add_library(xlsxwriter++ STATIC ${LXWPP_SOURCES})
else()
    add_library(xlsxwriter++ SHARED ${LXWPP_SOURCES})
endif()

set(LIBXLSXWRITERPP_INCLUDE_DIRS include libxlsxwriter/include)
set(LIBXLSXWRITERPP_LIBRARIES xlsxwriter++)
