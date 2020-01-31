#include "uls.h"

static bool own_cmp(void *a, void *b) {
    if (mx_strcmp((char *)a, (char *)b) > 0)
        return 1;
    else
        return 0;
}

static int mx_lines_count(int files_count, int *columns, int longest_name) {
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

static int *mx_sort_for_columns(int lines, int columns, int files_count) {
    int *sorted_list = (int *)malloc(sizeof(int) * files_count + 1);
    int index = 0;
    int i = 0;
    int counter = 0;

    for (i = 0; i < files_count; i++)
        sorted_list[i] = -1;
    sorted_list[i] = -2;
    i = 0;
    while (index < files_count) {
        if (counter == columns - 1) {
            counter = 0;
            i++;
        }
        sorted_list[index] = lines - 1 * counter; // NEED TO FINISH FORMULA)))
        printf("Index = %d, value : %d + (%d - 1) * %d\n", index, index , lines, counter);
        index++;
        counter++;
    }
    return sorted_list;
}

void mx_print_uls(t_list **files) {
    t_list *buf = *files;
    int files_count = mx_list_size(buf);
    int *columns = (int *)malloc(sizeof(int));
    int longest_name = mx_longest_name(buf);
    int lines = mx_lines_count(files_count, columns, longest_name);

    mx_sort_list(buf, &own_cmp);
    int *sorted_list = mx_sort_for_columns(lines, *columns, files_count);
    printf("\n");
    for (int i = 0; sorted_list[i] != -2; i++)
        printf("%d | ", sorted_list[i]);
    printf("\n");
    printf("LINES = %d\n", lines);
    printf("COLUMNS = %d\n", *columns);
    printf("FILES_COUNT = %d\n", files_count);
//    while (buf) {
//        mx_printstr(buf->data);
//        mx_printchar('\n');
//        buf = buf->next;
//    }
    free(columns);
    free(sorted_list);
}
