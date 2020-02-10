#include "uls.h"

bool mx_check_for_flags(char *str, char flag) {
    if (str) {
        for (int i = 0; str[i]; i++)
            if (str[i] == flag)
                return 1;
    }
    return 0;
}
