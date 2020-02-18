#include "uls.h"

char *mx_strjoin_for_path(char *argv, char *data) {
    char *part = NULL;
    char *full = NULL;

    part = mx_strjoin("/", data);
	full = mx_strjoin(argv, part);
	mx_strdel(&part);
    return full;
}
