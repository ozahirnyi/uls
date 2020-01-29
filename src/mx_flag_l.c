#include "uls.h"

void mx_flag_l(int argc, char *argv[]) {
	DIR *pointer = opendir(argv[1]);
    struct stat buf;
    struct dirent *box;
    argc = 2;
    stat(argv[1], &buf);
    if (pointer == NULL) {
        printf("ty loh");
        exit(1);
    }
    box = readdir(pointer);
    printf("%o\t",buf.st_mode);
    printf("%ld\n",buf.st_mtime);
    while (box != NULL) {
        printf("%s\t",box->d_name);
        printf("%c\n",box->d_type);
        box = readdir(pointer);
    }
}
