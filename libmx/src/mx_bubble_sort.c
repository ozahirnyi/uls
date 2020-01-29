#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int i = 0;
    int j = 0;
    int count = 0;
    char *buf;

    while (j++ <= size) {
        while (i++ < size - 1) {
            if (mx_strcmp(arr[i], arr[i + 1]) > 0) {
                buf = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buf;
                count++;
            }
        }
        i = 0;
    }
    return count;
}
