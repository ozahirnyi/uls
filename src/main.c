#include "uls.h"

int main(int argc, char **argv) {
	mx_read_uls(argv, argc);
    printf("\n\n");
    system("leaks -q uls");
    return 0;
}
