cmake_minimum_required(VERSION 3.12)
project(pathfinder C)

set(CMAKE_C_STANDARD 11)

include_directories("inc")
include_directories("libmx/inc")
#include("inc/pathfinder.h")

aux_source_directory(libmx/src LIB_SRC)
add_library(mx STATIC ${LIB_SRC})

#include_directories(inc)

add_executable(uls src/main.c src/mx_write_uls.c)

target_link_libraries(uls mx)