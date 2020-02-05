#include "uls.h"

static bool own_cmp(void *a, void *b) {
    if (mx_strcmp((char *)a, (char *)b) > 0)
        return 1;
    else
        return 0;
}

static t_list *mx_sort_for_columns(int lines, int col, int files_count) {
    t_list *sorted_list = NULL;
    int index = 0;
    int i = 0;
    int counter = 0;
    int *buf = NULL;

    while (index < files_count) {
        if (counter == col) {
            counter = 0;
            i++;
        }
        if (lines * counter + i < files_count) {
            buf = (int *)malloc(sizeof(int));
//            printf("------");
            buf[0] = lines * counter + i;
            mx_push_back(&sorted_list, buf);
        }
        else
            index--;
        index++;
//        printf("value : (%d * %d) + %d = %d\n", lines, counter, i, buf[0]);
//        printf("INDEX = %d\n", index);
        counter++;
    }
    return sorted_list;
}

static void tab_corrector(char *str) {
    int counter = 0;
    int i = 0;

    while (str[i]) {
        i++;
        counter++;
        if (counter == 8)
            counter = 0;
    }
    while (counter < 8) {
        mx_printchar(' ');
        counter++;
    }
}

static void printer(t_list *sorted_list, t_list **files, int *buf, int files_count, int lines, int longest) {
    t_list *bud = *files;
    int index = *(int *)sorted_list->data;

    while (index) {
        bud = bud->next;
        index--;
    }
    mx_printstr((const char *)bud->data);
    if (sorted_list->next) {
        buf[1] = *(int *)sorted_list->next->data;
        if (buf[0] > buf[1] || files_count == lines)
            mx_printchar('\n');
        else
            tab_corrector((char *)bud->data);
    }
}

void mx_print_uls(t_list **files, t_list *sorted_list) {
    int files_count = mx_list_size(*files);
    int *columns = (int *)malloc(sizeof(int));
    int longest_name = mx_longest_name(*files);
    int lines = mx_lines_count(files_count, columns, longest_name);
    int *buf = (int *)malloc(sizeof(int ) * 2);

    sorted_list = mx_sort_for_columns(lines, *columns, files_count);
    mx_sort_list(*files, &own_cmp);
    while (sorted_list) {
        buf[0] = *(int *)sorted_list->data;
        printer(sorted_list, files, buf, files_count, lines);
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
    free(buf);
    free(columns);
    free(sorted_list);
}
