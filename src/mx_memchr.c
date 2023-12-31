#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *p = s;
    unsigned char uc = (unsigned char)c;

    for (size_t i = 0; i < n; i++) {
        if (p[i] == uc) {
            return (void *)(p + i);
        }
    }

    return NULL;
}
