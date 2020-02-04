#include "uls.h"

void mx_l_out_st_mode(unsigned long n, char *name) {
    acl_t acl = NULL;
    ssize_t attr = 0;
    char *str = name;
    char prava[12];

    prava[1] = (n & S_IRUSR) == S_IRUSR ? 'r' : '-';
    prava[2] = (n & S_IWUSR) == S_IWUSR ? 'w' : '-';
    prava[3] = (n & S_IXUSR) == S_IXUSR ? 'x' : '-';
    prava[4] = (n & S_IRGRP) == S_IRGRP ? 'r' : '-';
    prava[5] = (n & S_IWGRP) == S_IWGRP ? 'w' : '-';
    prava[6] = (n & S_IXGRP) == S_IXGRP ? 'x' : '-';
    prava[7] = (n & S_IROTH) == S_IROTH ? 'r' : '-';
    prava[8] = (n & S_IWOTH) == S_IWOTH ? 'w' : '-';
    prava[9] = (n & S_IXGRP) == S_IXGRP ? 'x' : '-';
    if ((n & S_IFBLK) == S_IFBLK) /* spec block */
        prava[0] = 'b';
    else if ((n & S_IFDIR) == S_IFDIR) /* directory */
        prava[0] = 'd';
    else if ((n & S_IFLNK) == S_IFLNK) /* link */
        prava[0] = 'l';
    else if ((n & S_IFCHR) == S_IFCHR) /* spec char */
        prava[0] = 'c';
    else 
        prava[0] = '-';
    if ((n & S_ISUID) == S_ISUID)
        prava[3] = 's';
    if ((n & S_ISGID) == S_ISGID)
        prava[6] = 's';
    if ((n & S_ISVTX) == S_ISVTX)
        prava[9] = 't';
    attr = listxattr(str, NULL, 0, XATTR_NOFOLLOW);
    acl = acl_get_file(str, ACL_TYPE_EXTENDED);
    if (attr > 0) {
        prava[10] = '@';
        acl_free(acl);
    }
    else if (acl != NULL) {
        prava[10] = '+';
        acl_free(acl);
    }
    mx_printstr(prava);
    mx_printchar('\t');
}
