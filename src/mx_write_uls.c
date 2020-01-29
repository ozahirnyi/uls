#include "uls.h"

static

static void mx_print_uls(t_list **files) {
    t_list *buf = *files;

    mx_sort_list(buf, )
}

static void mx_read_directory(char *source, t_list **files) {
    DIR *directory = opendir(source);
    struct dirent *lupa = NULL;

    while ((lupa = readdir(directory)) != NULL) {
        char *buf = mx_strdup(lupa->d_name);
        mx_push_front(files, buf);
    }
    closedir(directory);
}

void mx_write_uls(char **source, int argc) {
    t_list *files = NULL;

    if (argc > 1)
        for (int i = 1; source[i] != NULL; i++)
            mx_read_directory(source[i], &files);
    else
        mx_read_directory(".", &files);
    while (files)
        mx_pop_front(&files);
}
