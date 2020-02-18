#include "uls.h"
void mx_read_uls(char **source, s_flags *flags) {
    t_list *sorted_list = NULL;
    t_list *files = NULL;
    int size = mx_arrlen(source);

    if (source && *source) {
        mx_bubble_sort(source, size);
        for (int i = 0; source[i]; i++) {
            mx_read_directory(source[i], &files, flags);
            mx_sort_list(files, &mx_compare);
            if (source[1])
                mx_dir_name_print(i, source);
            //if (flags->S)
            //    mx_sort_by_size(files, source[i]);
            // else if
            if (flags->t || flags->u)
               mx_sort_by_time(flags, files, source[i]);
            if (flags->l || flags->o || flags->g)
                mx_flag_l(files, source[i], flags);
            else if (flags->one)
                mx_flag_one(files);
            else
                mx_print_uls(&files, sorted_list);
            while (files)
                mx_pop_front(&files);
        }
    }
    else {
        mx_read_directory(".", &files, flags);
        mx_sort_list(files, &mx_compare);
        //if (flags->S)
        //    mx_sort_by_size(files, ".");
        // else if 
        if (flags->t || flags->u)
           mx_sort_by_time(flags, files, "."); 
        if (flags->l || flags->o || flags->g)
            mx_flag_l(files, ".", flags);
        else if (flags->one)
            mx_flag_one(files);
        else
           mx_print_uls(&files, sorted_list);
    }
    while (files)
        mx_pop_front(&files);
}
