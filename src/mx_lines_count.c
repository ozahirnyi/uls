#include "uls.h"

int mx_lines_count(int files_count, int *columns, int longest_name) {
    struct winsize window;
    int lines = 0;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    *columns = window.ws_col / longest_name;
    if (files_count % *columns == 0)
        lines = files_count / *columns;
    else
        lines = (files_count / *columns) + 1;
    return lines;
}
