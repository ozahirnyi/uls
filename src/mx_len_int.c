#include "uls.h"

int mx_len_int(unsigned long n) {
    int count = 0;
    int temp = n;

    while (temp > 0){
        temp = temp/10;
        count++;
    }
    return count;
}
