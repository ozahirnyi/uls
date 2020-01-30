#include "uls.h"

void mx_l_out_st_uid(unsigned int n) {
	struct passwd *username;

	username = getpwuid(n);
    mx_printstr(username->pw_name);
    mx_printchar('\t');
}
