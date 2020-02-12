#include "uls.h"

static void dir_name_print(int i, char **source) {
    if (i > 1)
        mx_printstr("\n\n");
    mx_printstr(source[i]);
    mx_printchar(':');
    mx_printchar('\n');
}

static void read_directory(char *source, t_list **files, s_flags *flags) {
    DIR *directory = opendir(source);
    struct dirent *lupa = NULL;
    char *buf = NULL;

    if (directory) {
        while ((lupa = readdir(directory)) != NULL) {
            if ((!flags->a && (mx_strcmp(lupa->d_name, ".") && mx_strcmp(lupa->d_name, "..")))
                 || flags->a || (flags->A && (mx_strcmp(lupa->d_name, ".") && mx_strcmp(lupa->d_name, "..")))) {
                buf = mx_strdup(lupa->d_name);
                mx_push_front(files, buf);
            }
        }
        closedir(directory);
    }
    else {
        buf = mx_strdup(source);
        mx_push_front(files, buf);
    }
}

void mx_read_uls(char **source, s_flags *flags) {
    t_list *sorted_list = NULL;
    t_list *files = NULL;

    if (source) {
        for (int i = 0; source[i] != NULL; i++) {
            read_directory(source[i], &files, flags);
            dir_name_print(i, source);
            mx_print_uls(&files, sorted_list);
            while (files)
                mx_pop_front(&files);
        }
    }
    else {
        read_directory(".", &files, flags);
        mx_print_uls(&files, sorted_list);
    }
    while (files)
        mx_pop_front(&files);

}
