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

static t_list *mx_sort_for_columns(int lines, int col, int files_count) {
    t_list *sorted_list = NULL;
    int index = 0;
    int i = 0;
    int counter = 0;

    while (index <= files_count) {
        if (counter == col) {
            counter = 0;
            i++;
        }
        if (lines * counter + i <= files_count) {
            int *buf = (int *)malloc(sizeof(int));
            buf[0] = lines * counter + i;
            printf("value : (%d * %d) + %d = %d\n", lines, counter, i, buf[0]);
            mx_push_back(&sorted_list, buf);
        }
        index++;
        counter++;
    }
    return sorted_list;
}

void mx_print_uls(t_list **files) {
    t_list *sorted_list = NULL;
    int files_count = mx_list_size(*files);
    int *columns = (int *)malloc(sizeof(int));
    int longest_name = mx_longest_name(*files);
    int lines = mx_lines_count(files_count, columns, longest_name);

    mx_sort_list(*files, &own_cmp);
    sorted_list = mx_sort_for_columns(lines, *columns, files_count);
    printf("\n");
    while (sorted_list) {
        int *buf = (int*)sorted_list->data;
        printf("%d | ", buf[0]);
        mx_pop_front(&sorted_list);
    }
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
