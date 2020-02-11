#include "uls.h"

static void mx_read_directory(char *source, t_list **files) {
    DIR *directory = opendir(source);
    struct dirent *lupa = NULL;
    char *buf = NULL;

    if (directory) {
        while ((lupa = readdir(directory)) != NULL) {
            buf = mx_strdup(lupa->d_name);
            mx_is_ascii(buf, mx_strlen(buf));
            mx_push_front(files, buf);
        }
        closedir(directory);
    }
    else {
        buf = mx_strdup(source);
        mx_push_front(files, buf);
    }
}

void mx_read_uls(char **source, char *flags) {
    t_list *sorted_list = NULL;
    t_list *files = NULL;

    if (source)
        for (int i = 0; source[i]; i++)
            mx_read_directory(source[i], &files);
    else {
        source[1] = mx_strdup(".");
        mx_read_directory(".", &files);
    }
    mx_sort_list(files, &mx_compare);
    if (mx_check_for_flags(flags, 'l'))
        for (int i = 0; source[i]; i++)
            mx_flag_l(files, source[i]);
    else
        mx_print_uls(&files, sorted_list);
    while (files)
        mx_pop_front(&files);
}
