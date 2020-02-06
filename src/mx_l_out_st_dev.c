#include "uls.h"

void mx_l_out_st_dev(unsigned int n, int otstup) {
    int i;
    int len = otstup - mx_len_int(n);
    int minor = MX_MINOR(n);
    char *minor_hex = NULL;

    for (i = 0; i < len; i++) {
       mx_printchar(' ');
    }
    mx_printint(MX_MAJOR(n));
    mx_printstr(", ");
    if (minor > 255) {
        minor_hex = mx_nbr_to_hex(minor);
        mx_printstr("0x");
        write(1, "00000000", 8 - mx_strlen(minor_hex));
        mx_printstr(minor_hex);
    }
    else
        mx_printint(minor);
    mx_printchar(' ');
    mx_strdel(&minor_hex);
}
