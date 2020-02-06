#include "uls.h"

int mx_max_len_char(t_list *names, int trig, char *argv) {
    int len = 0;
    t_list *p = names;
    struct stat buf;
    int n = 0;
    char *full_path = NULL;
    char *part = NULL;
    struct passwd *username;
    struct group *gr;

    while (p) {
        part = mx_strjoin("/",p->data);
        full_path = mx_strjoin(argv, part);
        lstat(full_path, &buf);
        if (trig == 1) {
            username = getpwuid(buf.st_uid);
            n = mx_strlen(username->pw_name);
        }
        if (trig == 2) {
            gr = getgrgid(buf.st_gid);
            if (gr != NULL)
                n = mx_strlen(gr->gr_name);
        }
        if (n > len)
            len = n;
        p = p->next;
        mx_strdel(&full_path);
        mx_strdel(&part);
    }
    return len;
}
