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

static int flag_counter(char **argv) {
    int i = 1;
    int counter = 0;

    while (argv[i]) {
        if (argv[i][0] == '-' && argv[i][1])
            for (int q = 1; argv[i][q]; q++)
                counter++;
        i++;
    }
    return counter;
}

int main(int argc, char **argv) {
    int ways_count = way_counter(argv);
    int flags_count = flag_counter(argv);
    char **ways = (char **)malloc(sizeof(char *) * ways_count + 1);
    char *flags = (char *)malloc(sizeof(char) * flags_count + 1);
    int count1 = 0;
    int count2 = 0;

    if (argc > 1) {
        int j = 0;

        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-' && argv[i][1] != '-')
                for (j = 1; argv[i][j]; j++)
                    flags[count1++] = argv[i][j];
            else
                ways[count2++] = mx_strdup(argv[i]);
        }
    }
    flags[count1] = '\0';
    ways[ways_count][0] = '\0';
     if (ways) {
         for (int i = 0; ways[i][0] != '\0'; i++) {
             mx_printstr(ways[i]);
             mx_printchar('\n');
         }
     }
    mx_printstr(flags);
    //mx_read_uls(ways, flags);
    printf("\n\n");
    //system("leaks -q uls");
    return 0;
}
