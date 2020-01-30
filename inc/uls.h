#ifndef ULS_H
#define ULS_H

//#include "libmx.h"
#include <sys/stat.h>
//#include <sys/stat.h>
#include "libmx/inc/libmx.h"
#include <time.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>

void mx_write_uls(char **source, int argc);
void mx_flag_l(int argc, char *argv[]);
void mx_l_out_st_mode(unsigned long n);
void mx_l_out_st_nlink(unsigned long n);
void mx_l_out_st_uid(unsigned int n);
void mx_l_out_st_gid(unsigned long n);
void mx_l_out_st_size(unsigned long n);
void mx_l_out_st_mtime(long n);

#endif
