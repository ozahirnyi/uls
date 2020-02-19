#include "uls.h"

static char *part_1(int len, char *date) {
    int i;
    int j = 0;
    char *new = (char *) malloc(sizeof(char *) * len);

    for (i = 4; i < len - 14; i++) {
        new[j] = date[i];
        j++;
    }
    new[j] = ' ';
    j++;
    for (i = len - 5; i < len - 1; i++) {
        new[j] = date[i];
        j++;
    }
    new[len] = ' ';
    return new;
}

static char *part_2(int len, char *date) {
    int i;
    int j = 0;
    char *new = (char *) malloc(sizeof(char *) * len);

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

static char *mx_l_change_date(char *date, long n, s_flags *fl) {
    int len = mx_strlen(date);
    long days_diff = time(NULL);
    char *new = NULL;

    if (!fl->T) {
        if ((days_diff - n)/86400 > 183) {
            new = part_1(len, date);
        }
        else {
            new = part_2(len, date);
        }
    }
    else {
        new = date;
        new[len - 1] = '\0';
    }
    return new;
}

void mx_l_out_st_mtime(long a, long m, long c, long b, s_flags *fl) {
    char *date = NULL;

    date = ctime(&m);
    if (fl->u)
        date = ctime(&a);
    if (fl->U)
        date = ctime(&b);
    if (fl->c)
        date = ctime(&c);
    date = mx_l_change_date(date, m, fl);
    mx_printstr(date);
    mx_printchar(' ');
    if (malloc_size(date))
        free(date);
}
