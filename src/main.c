#include "uls.h"

int main(int argc, char **argv) {
//    mx_flag_l(argc, argv);
    mx_write_uls(argv, argc);
    printf("\n\n");
    system("leaks -q uls");
    return 0;
}
