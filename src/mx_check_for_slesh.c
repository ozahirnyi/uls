#include "uls.h"

bool mx_check_for_slesh(char *argv) {
	int i = mx_strlen(argv);

	while (argv[i]) {
		if (argv[i] == '/')
			return true;
		i--;
	}
	return false;
}
