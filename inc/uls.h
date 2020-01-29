#ifndef ULS_H
#define ULS_H

//#include "libmx.h"
#include <sys/stat.h>
#include "libmx/inc/libmx.h"
#include <time.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>

typedef struct files {
    char *names;
} s_file;

void mx_flag_l(int argc, char *argv[]);

#endif
