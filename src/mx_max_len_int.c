#include "uls.h"

static int part(int trig, struct stat buf) {
    int n = 0;

    if (trig == 1)
        n = mx_len_int(buf.st_nlink);
    if (trig == 2)
        n = mx_len_int(buf.st_size);
    if (trig == 3)
        n = mx_len_int(MX_MAJOR(buf.st_rdev));
    if (trig == 4)
        n = mx_len_int(MX_MINOR(buf.st_rdev));
    return n;
}

int mx_max_len_int(t_list *names, int trig, char *argv) {
    int len = 0;
    t_list *p = names;
    struct stat buf;
    int n = 0;
    char *full_path = NULL;

    while (p) {
        full_path = mx_strjoin_for_path(argv, p->data);
        lstat(full_path, &buf);
        n = part(trig, buf);
        if (n > len)
            len = n;
        p = p->next;
        mx_strdel(&full_path);
    }
    return len;
}
