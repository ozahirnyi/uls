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
    char **ways = (char **)malloc(sizeof(char *) * ways_count + 1);
    int count = 0;
    flags *list_for_trig = NULL;

    if (argc > 1) {
        int j = 0;

        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-' && argv[i][1] != '-')
                for (j = 1; argv[i][j]; j++)
                    mx_flags_trig(argv[i][j], list_for_trig);
            else
                ways[count++] = mx_strdup(argv[i]);
        }
    }
    ways[ways_count] = NULL;
    mx_read_uls(ways, flags);
    printf("\n\n");
    system("leaks -q uls");
    return 0;
}
