#include "uls.h"

//static char *path_for_error(char *str) {
//    int max_len = mx_strlen(str) - 1;
//    int temp_len = max_len;
//    char *res = NULL;
//
//    while (str[temp_len - 1] != '/')
//        temp_len--;
//    res = mx_strnew(max_len - temp_len);
//    for (int i = 0; str[temp_len]; temp_len++) {
//        res[i] = str[temp_len];
//        i++;
//    }
//    return res;
//}

static bool trig_a(char *d_name, s_flags *flags) {
    if (flags->a
        || (flags->A && (mx_strcmp(d_name, ".") && mx_strcmp(d_name, "..")))
        || (!flags->a && !flags->A && (mx_strcmp(d_name, ".")
        && mx_strcmp(d_name, "..") && d_name[0] != '.')))
        return 1;
    else
        return 0;
}

static void mx_part_1(t_list **dirs, s_flags *flags, DIR *directory) {
    struct dirent *lupa = NULL;
    char *buf = NULL;

    while ((lupa = readdir(directory)) != NULL) {
        if (trig_a(lupa->d_name, flags)) {
            buf = mx_strdup(lupa->d_name);
            mx_push_front(files, buf);
        }
    }
    closedir(directory);
    flags->X = 1;
}

int mx_read_directory(char *source, t_list **files, s_flags *flags, t_list *dirs) {
    DIR *directory = opendir(source);
    char *buf = NULL;
    struct stat lt;
    int err = 0;

    lstat(source, &lt);
    if ((lt.st_mode & S_IFMT) == S_IFDIR)
        mx_part_1(dirs, flags, directory);
    else {
        buf = mx_strdup(source);
        mx_push_front(files, buf);
        flags->X = 0;
    }
    return err;
}
