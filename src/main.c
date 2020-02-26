#include "uls.h"

static char **ways_creator(char **argv, char **files, s_index *index, s_flags *flags) {
    int i = 0;
    int j = 0;
    char **dirs = (char **)malloc(sizeof(char *) * index->argc - index->index + 1);
    struct stat lt;

    for (; index->index < index->argc; index->index++) {
        if (lstat(argv[index->index], &lt) != -1) {
            if ((lt.st_mode & S_IFMT) == S_IFDIR) {
                dirs[i] = mx_strdup(argv[index->index]);
                i++;
            }
            else {
                files[j] = mx_strdup(argv[index->index]);
                j++;
            }
        }
        else {
            flags->err = 1;
            mx_printerr("uls: ");
            perror(argv[index->index]);
        }
    }
    files[j] = NULL;
    dirs[i] = NULL;
    return dirs;
}

static void parser(char **argv, s_index *index, s_flags *flags, char **files) {
    char **dirs = NULL;

    for (; argv[index->index] && argv[index->index][0] == '-'
        && argv[index->index][1]; index->index++) {
        if (argv[index->index][1] == '-' && !argv[index->index][2]) {
            index->index++;
            break;
        }
        for (int q = 1; argv[index->index][q]; q++)
            mx_flags_trig(argv[index->index][q], flags);
    }
    files = (char **)malloc(sizeof(char *) * index->argc - index->index + 1);
    dirs = ways_creator(argv, files, index, flags);
    mx_read_uls(files, dirs, flags);
    mx_del_strarr(&files);
    mx_del_strarr(&dirs);
}

int main(int argc, char **argv) {
    s_flags *flags = mx_flags_obnulyator();
    s_index *index = (s_index *)malloc(sizeof(s_index));
    char **files = NULL;

    index->argc = argc;
    index->index = 1;
    flags->err = 0;
    flags->Y = 0;
    if (argc > 1)
        parser(argv, index, flags, files);
    else
        mx_read_uls(NULL,NULL, flags);
    system("leaks -q uls");
    printf("\n\n");
    return flags->err;
}
