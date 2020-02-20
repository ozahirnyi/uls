#include "uls.h"

static void parser(char **argv, int argc, s_flags *flags) {
    char **ways = NULL;
    int index = 1;
    int i = 0;

    for (; argv[index] && argv[index][0] == '-' && argv[index][1]; index++) {
        if (argv[index][1] == '-' && !argv[index][2]) {
            index++;
            break;
        }
        for (int q = 1; argv[index][q]; q++)
            mx_flags_trig(argv[index][q], flags);
    }
    ways = (char **)malloc(sizeof(char *) * argc - index + 1);
    for (; index < argc; index++, i++)
        ways[i] = mx_strdup(argv[index]);
    ways[i] = NULL;
    mx_read_uls(ways, flags);
    mx_del_strarr(&ways);
}

int main(int argc, char **argv) {
    s_flags *flags = mx_flags_obnulyator();

    if (argc > 1)
        parser(argv, argc, flags);
    else
        mx_read_uls(NULL, flags);
//    printf("\n\n");
//    system("leaks -q uls");
    return 0;
}
