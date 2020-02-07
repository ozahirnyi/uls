#include "uls.h"

static int is_user(unsigned int st_uid, int n) {
    struct passwd *username;

    username = getpwuid(st_uid);
    n = mx_strlen(username->pw_name);
    return n;
}

static int is_group(unsigned int st_gid, int n) {
    struct group *gr;

    gr = getgrgid(st_gid);
    if (gr != NULL)
        n = mx_strlen(gr->gr_name);
    return n;
}

int mx_max_len_char(t_list *names, int trig, char *argv) {
    int len = 0;
    t_list *p = names;
    struct stat buf;
    int n = 0;
    char *full_path = NULL;

    while (p) {
        full_path = mx_strjoin_for_path(argv, p->data);
        lstat(full_path, &buf);
        if (trig == 1)
            n = is_user(buf.st_uid, n);
        if (trig == 2)
            n = is_group(buf.st_gid, n);
        if (n > len)
            len = n;
        p = p->next;
        mx_strdel(&full_path);
    }
    return len;
}
