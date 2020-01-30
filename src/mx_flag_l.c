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

static void mx_l_part_1(char *argv, DIR *pointer) {
    struct stat buf;
    struct dirent *box;
    long len = 0;

    argv = "lol";
    mx_printstr("total ");
    mx_printint(len);
    mx_printstr("\n");
    box = readdir(pointer);
    while (box != NULL) {
        lstat(mx_strjoin("./",box->d_name), &buf);
        mx_l_out_st_mode(buf.st_mode);
        mx_l_out_st_nlink(buf.st_nlink);
        mx_l_out_st_uid(buf.st_uid);
        mx_l_out_st_gid(buf.st_gid);
        mx_l_out_st_size(buf.st_size);
        mx_l_out_st_mtime(buf.st_mtime);
        mx_printstr(box->d_name);
        mx_printchar('\n');
        box = readdir(pointer);
    }
}

void mx_flag_l(int argc, char *argv[]) {
	DIR *pointer = NULL;

    if (argc == 1)
        pointer = opendir(".");
    else 
        pointer = opendir(argv[1]);
    mx_l_part_1(argv[1], pointer);
}
