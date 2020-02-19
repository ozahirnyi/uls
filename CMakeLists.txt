cmake_minimum_required(VERSION 3.12)
project(pathfinder C)

set(CMAKE_C_STANDARD 11)

include_directories("inc")
include_directories("libmx/inc")
#include("inc/pathfinder.h")

aux_source_directory(libmx/src LIB_SRC)
add_library(mx STATIC ${LIB_SRC})

#include_directories(inc)

add_executable(uls
        src/main.c
        src/mx_flag_l.c
        src/mx_l_out_st_mode.c
        src/mx_l_out_st_nlink.c
        src/mx_l_out_st_uid.c
        src/mx_l_out_st_gid.c
        src/mx_l_out_st_size.c
        src/mx_l_out_st_dev.c
        src/mx_l_out_st_mtime.c
        src/mx_read_uls.c
        src/mx_print_uls.c
        src/mx_longest_name.c
        src/mx_lines_count.c
        src/mx_is_ascii.c
        src/mx_max_len_int.c
        src/mx_max_len_char.c
        src/mx_len_int.c
        src/mx_compare.c
        src/mx_sort_for_columns.c
        src/mx_strjoin_for_path.c
        src/mx_flags_trig.c
        src/mx_vivod_total.c
        src/mx_read_directory.c
        src/mx_dir_name_print.c
        src/mx_flag_one.c
        src/mx_flag_d.c
        src/mx_change_argv.c
        src/mx_list_swap.c
        src/mx_sort_by_time.c
        src/mx_sort_by_size.c
        src/mx_flags_obnulyator.c
        src/mx_flag_p.c)

target_link_libraries(uls mx)