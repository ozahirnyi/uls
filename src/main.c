#include "uls.h"

int main(void) {
    s_flags *flags = (s_flags *)malloc(sizeof(s_flags));

    flags->A = 0;
    flags->a = 0;
    flags->l = 0;
    char *source[4] = {"src", "libmx", "inc", NULL};
    mx_read_uls(source, flags);
    mx_printstr("\n\n");
    system("leaks -q uls");
    return 0;
}
