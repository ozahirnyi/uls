#include "uls.h"

static bool trig_a(char *d_name, s_flags *flags) {
    if (flags->a
        || (flags->A && (mx_strcmp(d_name, ".") && mx_strcmp(d_name, "..")))
        || (!flags->a && !flags->A && (mx_strcmp(d_name, ".")
        && mx_strcmp(d_name, "..") && d_name[0] != '.')))
        return 1;
    else
        return 0;
}

static void dir_name_print(int i, char **source) {
    if (i > 0)
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
            if (trig_a(lupa->d_name, flags)) {
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
    int size = mx_arrlen(source);

    if (source && *source) {
        mx_bubble_sort(source, size);
        for (int i = 0; source[i] != NULL; i++) {
            read_directory(source[i], &files, flags);
            mx_sort_list(files, &mx_compare);
            if (source[1])
                dir_name_print(i, source);
            if (!flags->l)
                mx_print_uls(&files, sorted_list);
            else
                mx_flag_l(files, source[i]);
            while (files)
                mx_pop_front(&files);
        }
    }
    else {
        read_directory(".", &files, flags);
        mx_sort_list(files, &mx_compare);
        if (!flags->l)
            mx_print_uls(&files, sorted_list);
        else
            mx_flag_l(files, ".");
    }
    while (files)
        mx_pop_front(&files);
}
