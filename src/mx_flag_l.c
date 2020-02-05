#include "uls.h"

// static int mx_max_len_char(t_list *names, char *full_path, char *str) {
//     int len;
//     t_list *p = names;
//     struct stat buf;
//     int n = 0;

//     while (p) {
//         lstat(full_path, &buf);
//         n = mx_strlen(buf.str);
//         if (len < n)
//         len = n;
//         p = p->next;
//     }
    
//     return len;
// }

static void mx_l_part_1(char *argv, t_list *names) {
    struct stat buf;
    char *full_path = NULL;
    char *part = NULL;
    t_list *p = names;
    char *link = mx_strnew(20);
    char *name;
    int otstup1 = mx_max_len_int(names, 1, argv);
    int otstup2 = mx_max_len_char(names, 1, argv);
    int otstup3 = mx_max_len_char(names, 2, argv);
    int otstup4 = mx_max_len_int(names, 2, argv);

    while (p) {
        part = mx_strjoin("/",p->data);
        full_path = mx_strjoin(argv, part);
        lstat(full_path, &buf);
        mx_l_out_st_mode(buf.st_mode, full_path);
        mx_l_out_st_nlink(buf.st_nlink, otstup1);
        mx_l_out_st_uid(buf.st_uid, otstup2);
        mx_l_out_st_gid(buf.st_gid, otstup3);
        mx_l_out_st_size(buf.st_size, otstup4);
        mx_l_out_st_mtime(buf.st_mtime);
        name = p->data;
        mx_is_ascii(name, mx_strlen(name));
        if ((buf.st_mode & S_IFLNK) == S_IFLNK) { /* link */
            readlink(full_path, link, 20);
            mx_printstr(name);
            mx_printstr(" -> ");
            mx_printstr(link);
        }
        else
            mx_printstr(name);
        mx_printchar('\n');
        mx_strdel(&full_path);
        mx_strdel(&part);
        p = p->next;
    }
    mx_strdel(&link);
}

void mx_flag_l(t_list *names, char **argv) {
    mx_l_part_1(argv[1], names);
}
