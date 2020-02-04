#include "uls.h"

// static int mx_max_len_char(char *argv) {
//     DIR *pointer = opendir(argv);
//     struct dirent *box;
//     struct stat buf;
//     int len;
//     int i;

//     box = readdir(pointer);
//     while (box != NULL) {
//         lstat(box->d_name, &buf);
//         len = mx_strlen()
//         if ()
//     }
//     closedir(pointer);
//     return len;
// }

static void mx_l_part_1(char *argv, t_list *names) {
    struct stat buf;
    char *full_path = NULL;
    char *part = NULL;
    t_list *p = names;

    while (p) {
        part = mx_strjoin("/",p->data);
        full_path = mx_strjoin(argv, part);
        lstat(full_path, &buf);
        mx_l_out_st_mode(buf.st_mode, full_path);
        mx_l_out_st_nlink(buf.st_nlink);
        mx_l_out_st_uid(buf.st_uid);
        mx_l_out_st_gid(buf.st_gid);
        mx_l_out_st_size(buf.st_size);
        mx_l_out_st_mtime(buf.st_mtimespec.tv_sec);
        mx_printstr(p->data);
        if (!mx_is_ascii(p->data, mx_strlen(p->data)))
            mx_printchar('?');
        mx_printchar('\n');
        mx_strdel(&full_path);
        mx_strdel(&part);
        p = p->next;
    }
}

void mx_flag_l(t_list *names, char **argv) {
    mx_l_part_1(argv[1], names);
}
