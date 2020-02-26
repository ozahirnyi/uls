#include "uls.h"

static void p_dir_name_S_t(t_list *data, s_flags *flags, char *source, int i) {
    if (flags->p)
        mx_flag_p(data, flags, source);
    if (flags->dir_print)
        mx_dir_name_print(i, source);
    if (flags->S)
        mx_sort_by_size(data, source);
    else if (flags->t)
        mx_sort_by_time(flags, data, source);
}

static void work_with_flags(s_flags *flags, t_list *data, char *source, int i) {
    t_list *sorted_list = NULL;

    p_dir_name_S_t(data, flags, source, i);
    if (flags->r)
        data = mx_list_reverse(data);
    if (flags->one)
        mx_flag_one(data);
    else if (flags->l || flags->o || flags->g) {
        if (!flags->X)
            while (data) {
                mx_flag_l(data, data->data, flags);
                data = data->next;
            }
        else
            mx_flag_l(data, source, flags);
    }
    else
        mx_print_uls(&data, sorted_list);
    while (data) {
        free(data->data);
        mx_pop_front(&data);
    }
}

static void list_creator(s_flags *flags, char *dirs, char **files, int i) {
    t_list *data = NULL;

    if (dirs) {
        mx_read_directory(dirs, &data, flags);
        mx_sort_list(data, &mx_compare);
        work_with_flags(flags, data, dirs, i);
    }
    else {
        flags->Y = 1;
        for (int i = 0; files[i]; i++)
            mx_push_front(&data, files[i]);
        mx_sort_list(data, &mx_compare);
        work_with_flags(flags, data, dirs, i);
    }
    if (files)
        mx_printchar('\n');
}

void mx_read_uls(char **files, char **dirs, s_flags *flags) {
    int size_files = mx_arrlen(files);
    int size_dirs = mx_arrlen(dirs);

    if (files && *files) {
        mx_bubble_sort(files, size_files);
        list_creator(flags, NULL, files, 0);
    }
    if (dirs && *dirs) {
        if (dirs[1])
            flags->dir_print = 1;
        mx_bubble_sort(dirs, size_dirs);
        for (int i = 0; dirs[i]; i++)
            list_creator(flags, dirs[i], NULL, i);
    }
    else if (dirs == NULL || files == NULL)
        list_creator(flags, ".", NULL, 0);
}
