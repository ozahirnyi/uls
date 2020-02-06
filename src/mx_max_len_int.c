#include "uls.h"

int mx_max_len_int(t_list *names, int trig, char *argv) {
    int len = 0;
    t_list *p = names;
    struct stat buf;
    int n = 0;
    char *full_path = NULL;
    char *part = NULL;

    while (p) {
        part = mx_strjoin("/",p->data);
        full_path = mx_strjoin(argv, part);
        lstat(full_path, &buf);
        if (trig == 1)
            n = mx_len_int(buf.st_nlink);
        if (trig == 2)
            n = mx_len_int(buf.st_size);
        if (n > len)
            len = n;
        p = p->next;
        mx_strdel(&full_path);
        mx_strdel(&part);
    }
    return len;
}
