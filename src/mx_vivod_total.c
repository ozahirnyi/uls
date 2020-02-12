#include "uls.h"

void mx_vivod_total(t_list *names, char *argv) {
	int sum = 0;
    t_list *p = names;
    struct stat buf;
    char *full_path = NULL;

    mx_printstr("total ");
    while (p) {
        full_path = mx_strjoin_for_path(argv, p->data);
        lstat(full_path, &buf);
        sum += buf.st_blocks;
        p = p->next;
        mx_strdel(&full_path);
    }
    mx_printint(sum);
    mx_printstr("\n");
}
