#include "uls.h"

void mx_change_argv(char *temp, int len) {
	int i = len - 1;

	while (temp[i] != '/'){
		temp[i] = '\0';
		i--;
	}
	temp[i] = '\0';
}
