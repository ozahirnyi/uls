#include "uls.h"

void mx_is_ascii(char *str, int len) {
	for (int i = 0; i < len; i++) {
    	if (str[i] >= 0 && str[i] <= 31)
            str[i] = '?';
	}
}
