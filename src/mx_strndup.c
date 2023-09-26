#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (s1 == NULL) {
        return NULL;
    }

    size_t length = 0;
    while (s1[length] != '\0' && length < n) {
        length++;
    }

    char *duplicate = (char *)malloc(length + 1);
    if (duplicate == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < length; i++) {
        duplicate[i] = s1[i];
    }
    duplicate[length] = '\0';

    return duplicate;
}
