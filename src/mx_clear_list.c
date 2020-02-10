#include "uls.h"

void mx_clear_list(t_list *list) {
    t_list *p1 = list;

    while (p1 != NULL) {
    	mx_pop_front(&p1);
    }
}
