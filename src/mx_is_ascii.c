#include "uls.h"

bool mx_is_ascii(char *str, int len) {
	int i;
	for (i = 0; i < len; i++) {
    	if (str[i] < 0 && str[i] > 127) 
        	return false;
	}
return true;
}
