#include "uls.h"

static char **ways_creator(char **argv, int argc, int index, char **files) {
    int i = 0;
    int j = 0;
    char **dirs = NULL;
    struct stat lt;

//    files = (char **)malloc(sizeof(char *) * argc - index + 1);
    dirs = (char **)malloc(sizeof(char *) * argc - index + 1);
    for (int q = 1; index < argc; index++) {
        stat(argv[q], &lt);
        if ((lt.st_mode & S_IFMT) == S_IFDIR) {
            dirs[i] = mx_strdup(argv[q]);
            i++;
        }
        else {
            files[j] = mx_strdup(argv[q]);
            j++;
        }
        q++;
    }
    files[j] = NULL;
    dirs[i] = NULL;
    return dirs;
}

static int parser(char **argv, int argc, s_flags *flags) {
    char **files = NULL;
    char **dirs = NULL;
    int index = 1;

    for (; argv[index] && argv[index][0] == '-' && argv[index][1]; index++) {
        if (argv[index][1] == '-' && !argv[index][2]) {
            index++;
            break;
        }
        for (int q = 1; argv[index][q]; q++)
            mx_flags_trig(argv[index][q], flags);
    }
    files = (char **)malloc(sizeof(char *) * argc - index + 1);
    dirs = ways_creator(argv, argc, index, files);
//    ways = (char **)malloc(sizeof(char *) * argc - index + 1);
//    for (; index < argc; index++, i++)
//        ways[i] = mx_strdup(argv[index]);
//    ways[i] = NULL;
//    printf("\n\n%s\n\n", dirs[0]);
//    printf("\n\n%s\n\n", files[0]);
    mx_read_uls(files, dirs, flags);
//    if (files)
//        mx_del_strarr(&files);
//    if (dirs)
//        mx_del_strarr(&dirs);
    return 0;
}

int main(int argc, char **argv) {
    s_flags *flags = mx_flags_obnulyator();
    flags->err = 0;
    flags->Y = 0;
//    struct stat lt;

//    if (lstat(source, &lt) < 0) {
//        mx_printerr("./uls: ");
//        perror(source);
//        flags->err = 1;
//    }
    if (argc > 1)
        parser(argv, argc, flags);
    else
        mx_read_uls(NULL,NULL, flags);
    //printf("\n\n");
    //system("leaks -q uls");
    return flags->err;
}
