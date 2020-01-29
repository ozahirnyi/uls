#include "uls.h"

char *change_date(char *date) {
    int i;
    int j = 0;
    int len = mx_strlen(date);
    char *new = (char *) malloc(sizeof(char *) * len);

    for (i = 4; i < len - 9; i++) {
        new[j] = date[i];
        j++;
    }
    new[len - 9] = ' ';
    for (i = len - 8; i < len; i++) {
        new[j] = '\0';
        j++;
    }
    return new;
}

void mx_flag_l(int argc, char *argv[]) {
	DIR *pointer = opendir(argv[1]);
    struct stat buf;
    struct dirent *box;
    char *date = NULL;
    struct passwd *username = NULL;
    argc = 2;
    if (pointer == NULL) {
        printf("ty loh");
        exit(1);
    }
    box = readdir(pointer);
    printf("total hui\n");
    while (box != NULL) {
        stat(box->d_name, &buf);
        printf("%hu\t",buf.st_mode);
        printf("%hu\t",buf.st_nlink);
        username = getpwuid(buf.st_uid);
        printf("%s\t",username->pw_name);
        printf("%u\t",buf.st_gid);
        printf("%lld\t",buf.st_size);
        date = ctime(&buf.st_mtime);
        date = change_date(date);
        printf("%s ",date);
        printf("%s\n",box->d_name);
        box = readdir(pointer);
    }
}
