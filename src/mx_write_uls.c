#include "uls.h"

static bool own_cmp(void *a, void *b) {
    if (mx_strcmp((char *)a, (char *)b) > 0)
        return 1;
    else
        return 0;
}

static void mx_print_uls(t_list **files) {
    t_list *buf = *files;
    mx_sort_list(buf, &own_cmp);
    while (buf) {
        mx_printstr(buf->data);
        mx_printchar('\n');
        buf = buf->next;
    }
}

static void mx_read_directory(char *source, t_list **files) {
    DIR *directory = opendir(source);
    struct dirent *lupa = NULL;

    if (directory) {
        while ((lupa = readdir(directory)) != NULL) {
            char *buf = mx_strdup(lupa->d_name);
            mx_push_front(files, buf);
        }
        closedir(directory);
    }
    else {
        char *buf = mx_strdup(source);
        mx_push_front(files, buf);
    }
}

void mx_write_uls(char **source, int argc) {
    t_list *files = NULL;

    if (argc > 1)
        for (int i = 1; source[i] != NULL; i++)
            mx_read_directory(source[i], &files);
    else
        mx_read_directory(".", &files);
    mx_print_uls(&files);
    while (files)
        mx_pop_front(&files);
}
