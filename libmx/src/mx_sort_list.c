#include "../inc/libmx.h"

bool cmp(void *a, void *b) {
    if (mx_strcmp((char *)a, (char *)b) > 0)
        return 1;
    else
        return 0;
}

void swaper(t_list *lst) {
    void *buf = NULL;
    
    buf = lst->data;
    lst->data = lst->next->data;
    lst->next->data = buf;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    int size = mx_list_size(lst);
    int i = 0;
    int j = 0;
    t_list *start = lst;

    while (j <= size) {
        while (i < size - 1) {
            if (cmp(start->data, start->next->data) == 1)
                swaper(start);
            start = start->next;
            i++;
        }
        i = 0;
        start = lst;
        j++;
    }
    return lst;
}
