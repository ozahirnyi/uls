#include "uls.h"

static int way_counter(char **argv) {
    int i = 1;
    int counter = 0;

    while (argv[i]) {
        if (argv[i][0] != '-')
            counter++;
        i++;
    }
    return counter;
}

int main(int argc, char **argv) {
    int ways_count = way_counter(argv);
    int count = 0;
    char **ways = NULL;
    s_flags *flags = (s_flags *)malloc(sizeof(s_flags));

    if (argc > 1) {
        ways = (char **)malloc(sizeof(char *) * ways_count + 1);
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-' && argv[i][1] != '-')
                for (int j = 1; argv[i][j]; j++)
                    mx_flags_trig(argv[i][j], flags);
            else
                ways[count++] = mx_strdup(argv[i]);
        }
        ways[ways_count] = NULL;
    }
    mx_read_uls(ways, flags);
    printf("\n\n");
    system("leaks -q uls");
    return 0;
}
