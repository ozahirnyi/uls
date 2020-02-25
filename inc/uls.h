#ifndef ULS_H
#define ULS_H

//#include "libmx.h"
#include "libmx/inc/libmx.h"
#include <sys/stat.h>
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
#include <malloc/malloc.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

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
#define MX_MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define MX_MINOR(x) ((int32_t)((x) & 0xffffff))

typedef struct print_uls {
    int files_count;
    int *columns;
    int longest_name;
    int lines;
    int *cast;
} s_print;

typedef struct flags {
    bool l;//+
    bool a;//+
    bool A;//+
    bool o;//+
    bool one;//+
    bool g;//+
    bool t;//+
    bool u;//+
    bool U;//+
    bool c;//+
    bool T;//+
    bool p;//+
    bool S;//+
    bool r;//-
    bool f;//-
    bool X;//triger na papku
    bool dir_print;//triger na papku
} s_flags;

t_list *mx_list_reverse(t_list *files);
t_list *mx_sort_for_columns(s_print *info);
bool mx_compare(void *a, void *b);
int mx_longest_name(t_list *list);
int mx_read_uls(char **files, char **dirs, s_flags *flags, int err);
int mx_lines_count(int files_count, int *columns, int longest_name);
int mx_read_directory(char *source, t_list **files, s_flags *flags, int err);
void mx_print_uls(t_list **files, t_list *sorted_list);
void mx_flag_l(t_list *names, char *argv, s_flags *flags);
void mx_l_out_st_blocks(unsigned long n, int otstup);
void mx_l_out_st_mode(unsigned long n, char *name);
void mx_l_out_st_nlink(unsigned long n, int otstup);
void mx_l_out_st_uid(unsigned int n, int otstup);
void mx_l_out_st_gid(unsigned long n, int otstup, s_flags *fl);
void mx_l_out_st_size(unsigned long n, int otstup);
void mx_l_out_st_dev(unsigned int n, int otstup1, int otstup2);
void mx_is_ascii(char *str, int len);
void mx_l_out_st_mtime(long *amcb, s_flags *fl);
int mx_max_len_int(t_list *names, int trig, char *argv);
int mx_max_len_char(t_list *src, int trig, char *argv);
char *mx_strjoin_for_path(char *argv, char *data);
int mx_len_int(unsigned long n);
void mx_flags_trig(char f, s_flags *trig);
void mx_vivod_total(t_list *names, char *argv);
void mx_dir_name_print(int i, char *source);
void mx_flag_one(t_list *names);
void mx_flag_d(char *source, t_list **files);
void mx_list_swap(t_list *lst);
void mx_sort_by_time(s_flags *fl, t_list *files, char *argv);
void mx_sort_by_size(t_list *files, char *argv);
s_flags *mx_flags_obnulyator();
void mx_flag_p(t_list *files, s_flags *fl, char *argv);

#endif
