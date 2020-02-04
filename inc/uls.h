#ifndef ULS_H
#define ULS_H

//#include "libmx.h"
#include <sys/stat.h>
#include "libmx/inc/libmx.h"
#include <time.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/acl.h>

#define S_IFMT   0170000  /* type of file mask */
#define S_IFIFO  0010000  /* named pipe (fifo) */
#define S_IFCHR  0020000  /* character special */
#define S_IFDIR  0040000  /* directory */
#define S_IFBLK  0060000  /* block special */
#define S_IFREG  0100000  /* regular */
#define S_IFLNK  0120000  /* symbolic link */
#define S_IFSOCK 0140000  /* socket */
#define S_IFWHT  0160000  /* whiteout */
#define S_ISUID  0004000  /* set user id on execution */
#define S_ISGID  0002000  /* set group id on execution */
#define S_ISVTX  0001000  /* save swapped text even after use */
#define S_IRWXU  0000700  /* RWX mask for owner */
#define S_IRUSR  0000400        /* R ead permission, owner */ 
#define S_IWUSR  0000200        /* W rite permission, owner */
#define S_IXUSR  0000100        /* X execute/search permission, owner */
#define S_IRWXG  0000070  /* RWX mask for group */
#define S_IRGRP  0000040        /* R ead permission, group */
#define S_IWGRP  0000020        /* W rite permission, group */
#define S_IXGRP  0000010        /* X execute/search permission, group */
#define S_IRWXO  0000007  /* RWX mask for other */
#define S_IROTH  0000004        /* R ead permission, other */
#define S_IWOTH  0000002        /* W rite permission, other */
#define S_IXOTH  0000001        /* X execute/search permission, other */

int mx_longest_name(t_list *list);
void mx_print_uls(t_list **files);
void mx_read_uls(char **source, int argc);
void mx_flag_l(t_list *names, char **argv);
void mx_l_out_st_mode(unsigned long n, char *name);
void mx_l_out_st_nlink(unsigned long n);
void mx_l_out_st_uid(unsigned int n);
void mx_l_out_st_gid(unsigned long n);
void mx_l_out_st_size(unsigned long n);
void mx_l_out_st_mtime(long n);
bool mx_is_ascii(char *str, int len);

#endif
