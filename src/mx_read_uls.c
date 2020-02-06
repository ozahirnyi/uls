#include "uls.h"

static void mx_read_directory(char *source, t_list **files) {
    DIR *directory = opendir(source);
    struct dirent *lupa = NULL;
    char *buf = NULL;

    if (directory) {
        while ((lupa = readdir(directory)) != NULL) {
            buf = mx_strdup(lupa->d_name);
            mx_push_front(files, buf);
        }
        closedir(directory);
    }
    else {
        buf = mx_strdup(source);
        mx_push_front(files, buf);
    }
}

void mx_read_uls(char **source, int argc) {
    t_list *sorted_list = NULL;
    t_list *files = NULL;

    if (argc > 1)
        for (int i = 1; source[i] != NULL; i++)
            mx_read_directory(source[i], &files);
    else
        mx_read_directory(".", &files);
    mx_print_uls(&files, sorted_list);
    while (files)
        mx_pop_front(&files);
}
