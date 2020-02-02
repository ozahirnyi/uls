#include "uls.h"

static char *mx_l_change_date(char *date, long n) {
    int i;
    int j = 0;
    int len = mx_strlen(date);
    char *new = (char *) malloc(sizeof(char *) * len);
    long days_diff = time(NULL);
    n = 0;
    days_diff = (days_diff - n)/86400;
    //mx_printint(days_diff);
    //mx_printchar('-');
    for (i = 4; i < len - 9; i++) {
        new[j] = date[i];
        j++;
    }
    new[len - 9] = ' ';
    for (i = len - 8; i < len; i++) {
        new[j] = '\0';
        j++;
    }
    return new;
}

void mx_l_out_st_mtime(long n) {
	char *date = NULL;

	date = ctime(&n);
    date = mx_l_change_date(date, n);
    mx_printstr(date);
    mx_printchar('\t');
    free(date);
}
