#include "../inc/libmx.h"

int mx_count_words(const char* str, char c) {
    int s = 0, d = 0;

    while (*str) {
        if (*str == c || *str == '\n'){
            s = 0;
        }
        else if (s == 0) {
            s = 1;
            d++;
        }
        str++;
    }

    return d;
}
