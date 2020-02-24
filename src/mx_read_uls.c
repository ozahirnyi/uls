#include "uls.h"

static void p_dir_name_S_t(t_list *files, s_flags *flags, char *source, int i) {
    if (flags->p)
        mx_flag_p(files, flags, source);
    if (flags->dir_print)
        mx_dir_name_print(i, source);
    if (flags->S)
        mx_sort_by_size(files, source);
    else if (flags->t)
        mx_sort_by_time(flags, files, source);
}

static int work_with_flags(s_flags *flags, char *source, int i, int err) {
    t_list *sorted_list = NULL;
    t_list *files = NULL;

    if (mx_read_directory(source, &files, flags, err) == 0) {
        mx_sort_list(files, &mx_compare);
        p_dir_name_S_t(files, flags, source, i);
         if (flags->r)
            files = mx_list_reverse(files);
        if (flags->one)
            mx_flag_one(files);
        else if (flags->l || flags->o || flags->g)
            mx_flag_l(files, source, flags);
        else
            mx_print_uls(&files, sorted_list);
        while (files) {
            free(files->data);
            mx_pop_front(&files);
        }
    }
    return err;
}

int mx_read_uls(char **source, s_flags *flags, int err) {
    int size = mx_arrlen(source);

    if (source && *source) {
        if (source[1])
            flags->dir_print = 1;
        mx_bubble_sort(source, size);
        for (int i = 0; source[i]; i++)
            work_with_flags(flags, source[i], i, err);
    }
    else
        work_with_flags(flags, ".", 0, err);
    return err;
}
