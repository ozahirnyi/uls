#include "uls.h"
#include <dirent.h>

//ZALUPA

void mx_read_directory(char *source, struct dirent *lupa) {
    DIR *directory = opendir(source);

    while ((lupa = readdir(directory)) != NULL) {
//        if (mx_strcmp(lupa->d_name, ".") && mx_strcmp(lupa->d_name, "..")) {
            mx_printstr(lupa->d_name);
            mx_printchar('\n');
//        }
    }
}

void mx_write_uls(char **source, int argc) {
    struct dirent *lupa = NULL;
//    s_file **file = (s_file **)malloc(sizeof(s_file *));

    if (argc > 1)
        for (int i = 1; source[i] != NULL; i++)
            mx_read_directory(source[i], lupa);
    else
        mx_read_directory(".", lupa);
}

int main(int argc, char **argv) {
    mx_write_uls(argv, argc);
//    struct stat *zhepa = NULL;
//    lstat("../inc", zhepa);
//    printf("%d\n", zhepa->st_birthtimespec);
//    printf("%d\n", zhepa->st_rdev);
//    printf("%u\n", zhepa->st_uid);
//    printf("CHECK");
//    DIR *directory;
//    struct dirent *zhupa = NULL;
//    directory = opendir(".");
//    while (readdir(directory)) {
//        zhupa = readdir(directory);
//        printf("%llu - %s [%d] %d %llu\n", zhupa->d_ino, zhupa->d_name, zhupa->d_type, zhupa->d_reclen, zhupa->d_seekoff);
//    }
//    closedir(directory);
    return 0;
}
