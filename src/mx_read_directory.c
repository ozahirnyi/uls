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

void mx_read_directory(char *source, t_list **files, s_flags *flags) {
    DIR *directory = opendir(source);
    struct dirent *lupa = NULL;
    char *buf = NULL;
    struct stat lt;

    lstat(source, &lt);
    if ((lt.st_mode & S_IFMT) == S_IFDIR) {
        while ((lupa = readdir(directory)) != NULL) {
            if (trig_a(lupa->d_name, flags)) {
                    buf = mx_strdup(lupa->d_name);
                mx_push_front(files, buf);
            }
        }
        closedir(directory);
        flags->X = 1;
    }
    else {
        buf = mx_strdup(source);
        mx_push_front(files, buf);
        flags->X = 0;
    }
}
