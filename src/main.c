#include "uls.h"

static char **ways_creator(char **argv, int argc, int index, char **files) {
    int i = 0;
    int j = 0;
    char **dirs = NULL;
    struct stat lt;

    dirs = (char **)malloc(sizeof(char *) * argc - index + 1);
    for (; index < argc; index++) {
        stat(argv[index], &lt);
        if ((lt.st_mode & S_IFMT) == S_IFDIR) {
            dirs[i] = mx_strdup(argv[index]);
            i++;
        }
        else {
            files[j] = mx_strdup(argv[index]);
            j++;
        }
    }
    files[j] = NULL;
    dirs[i] = NULL;
    return dirs;
}

static int parser(char **argv, int argc, s_flags *flags, int err) {
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
    mx_read_uls(files, dirs, flags, err);
    return err;
}

int main(int argc, char **argv) {
    s_flags *flags = mx_flags_obnulyator();
    int err = 0;

    if (argc > 1)
        parser(argv, argc, flags, err);
    else
        mx_read_uls(NULL,NULL, flags, err);
    //printf("\n\n");
    //system("leaks -q uls");
    return err;
}
