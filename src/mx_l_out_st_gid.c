#include "uls.h"

void mx_l_out_st_gid(unsigned long n) {
	struct group *gr;

	gr = getgrgid(n);
	if (gr != NULL)
    	mx_printstr(gr->gr_name);
    else
    	mx_printint(n);
    mx_printchar('\t');
}
