#include "uls.h"

static int *create_otstup(char *argv, t_list *names) {
    int *otstup = (int *) malloc(sizeof(int) * 6);

    otstup[1] = mx_max_len_int(names, 1, argv);
    otstup[2] = mx_max_len_char(names, 1, argv);
    otstup[3] = mx_max_len_char(names, 2, argv);
    otstup[4] = mx_max_len_int(names, 2, argv);
    otstup[5] = mx_max_len_int(names, 3, argv);
    otstup[6] = mx_max_len_int(names, 4, argv);
    otstup[0] = otstup[4];
    return otstup;
}

static void part_for_link (char *path, char *data)  {
    char *link = mx_strnew(20);

    readlink(path, link, 20);
    mx_printstr(data);
    mx_printstr(" -> ");
    mx_printstr(link);
    mx_strdel(&link);
}

static void part_1_of_cycle(int *otstup, struct stat buf,
                            char *full_path) {
    mx_l_out_st_mode(buf.st_mode, full_path);
    mx_l_out_st_nlink(buf.st_nlink, otstup[1]);
    mx_l_out_st_uid(buf.st_uid, otstup[2]);
    mx_l_out_st_gid(buf.st_gid, otstup[3]);
    if ((buf.st_mode & S_IFMT) == S_IFBLK
        || (buf.st_mode & S_IFMT) == S_IFCHR) {
        mx_l_out_st_dev(buf.st_rdev, otstup[5], otstup[6]);
        otstup[0] = otstup[4] + 3;
    }
    else
        mx_l_out_st_size(buf.st_size, otstup[0]);
}

static void part_2_of_cycle(struct stat buf, t_list *p,
                            char *full_path) {
    char *name = p->data;

    mx_l_out_st_mtime(buf.st_mtime);
    mx_is_ascii(name, mx_strlen(name));
    if ((buf.st_mode & S_IFLNK) == S_IFLNK)
        part_for_link(full_path, p->data);
    else
        mx_printstr(p->data);
    mx_printchar('\n');
}

void mx_flag_l(t_list *names, char *argv) {
    struct stat buf;
    char *full_path = NULL;
    t_list *p = names;
    int *otstup = create_otstup(argv, names);

    while (p) {
        full_path = mx_strjoin_for_path(argv, p->data);
        lstat(full_path, &buf);
        part_1_of_cycle(otstup, buf, full_path);
        part_2_of_cycle(buf, p, full_path);
        mx_strdel(&full_path);
        p = p->next;
    }
    free(otstup);
}
