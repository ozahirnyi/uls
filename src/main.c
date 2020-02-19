#include "uls.h"

//static int way_counter(char **argv) {
//    int i = 1;
//    int counter = 0;
//
//    while (argv[i]) {
//        if (argv[i][0] != '-')
//            counter++;
//        i++;
//    }
//    return counter;
//}

static void parser(char **argv, int argc, s_flags *flags, char **ways) {
//    int ways_count = ways_counter(argv);
    int index = 1;

    for (; argv[index][0] == '-' && argv[index][1] != '-'; index++)
        for (int i = 0; argv[index][i]; i++)
            mx_flags_trig(argv[index][i], flags);
    ways = (char **)malloc(sizeof(char *) * argc - index + 1);
    for (int i = 0; index < argc; index++, i++)
        ways[i] = mx_strdup(argv[index]);
}

int main(int argc, char **argv) {
    char **ways = NULL;
    s_flags *flags = mx_flags_obnulyator();

    if (argc > 1)
        parser(argv, argc, flags, ways);
    mx_read_uls(ways, flags);
    mx_del_strarr(&ways);
    printf("\n\n");
    system("leaks -q uls");
    return 0;
}
