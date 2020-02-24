#include "uls.h"

static int *create_otstup(char *argv, t_list *names) {
    int *otstup = (int *) malloc(sizeof(int) * 7);

    otstup[1] = mx_max_len_int(names, 1, argv);
    otstup[2] = mx_max_len_char(names, 1, argv);
    otstup[3] = mx_max_len_char(names, 2, argv);
    otstup[4] = mx_max_len_int(names, 2, argv);
    otstup[5] = mx_max_len_int(names, 3, argv);
    otstup[6] = mx_max_len_int(names, 4, argv);
    otstup[0] = otstup[4];
    return otstup;
}

static void part_for_link(char *path, char *data)  {
    char *link = mx_strnew(20);
    char *name = data;

    readlink(path, link, 20);
    mx_printstr(name);
    mx_printstr(" -> ");
    mx_printstr(link);
    mx_strdel(&link);
}

static void part_1_of_cycle(int *otstup, struct stat buf,
                            char *full_path, s_flags *fl) {
    mx_l_out_st_mode(buf.st_mode, full_path);
    mx_l_out_st_nlink(buf.st_nlink, otstup[1]);
    if (!fl->g)
        mx_l_out_st_uid(buf.st_uid, otstup[2]);
    if (!fl->o)
        mx_l_out_st_gid(buf.st_gid, otstup[3], fl);
    if ((buf.st_mode & S_IFMT) == S_IFBLK
        || (buf.st_mode & S_IFMT) == S_IFCHR) {
        if (!fl->X)
            mx_l_out_st_dev(buf.st_rdev, otstup[5] + 1, otstup[6]);
        else
            mx_l_out_st_dev(buf.st_rdev, otstup[5], otstup[6]);
        otstup[0] = otstup[4] + 7;
    }
    else
        mx_l_out_st_size(buf.st_size, otstup[0]);
}

static void part_2_of_cycle(struct stat buf, t_list *p,
                            char *full_path, s_flags *fl) {
    char *data = mx_strdup(p->data);
    long *amcb = (long *)malloc(sizeof(long) * 4);

    amcb[0] = buf.st_atime;
    amcb[1] = buf.st_mtime;
    amcb[2] = buf.st_ctime;
    amcb[3] = buf.st_birthtime;
    mx_l_out_st_mtime(amcb, fl);
    mx_is_ascii(data, mx_strlen(data));
    if ((buf.st_mode & S_IFLNK) == S_IFLNK)
        part_for_link(full_path, p->data);
    else
        mx_printstr(data);
    mx_printchar('\n');
    mx_strdel(&data);
    free(amcb);
}

void mx_flag_l(t_list *names, char *argv, s_flags *flags) {
    struct stat buf;
    int *otstup = create_otstup(argv, names);

    if (flags->X) {
        mx_vivod_total(names, argv);
        while (names) {
            char *full_path = mx_strjoin_for_path(argv, names->data);
            lstat(full_path, &buf);
            part_1_of_cycle(otstup, buf, full_path, flags);
            part_2_of_cycle(buf, names, full_path, flags);
            mx_strdel(&full_path);
            names = names->next;
        }
    }
    else {
        lstat(argv, &buf);
        part_1_of_cycle(otstup, buf, argv, flags);
        part_2_of_cycle(buf, names, argv, flags);
    }
    free(otstup);
}
