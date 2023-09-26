#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    int len = mx_strlen(str);
    int start = 0;

    while (start < len && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n' || str[start] == '\r')) {
        start++;
    }

    int end = len - 1;

    while (end >= 0 && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n' || str[end] == '\r')) {
        end--;
    }

    int trimmed_len = end - start + 1;
    if (trimmed_len <= 0) {
        return mx_strdup("");
    }
    char *trimmed_str = (char *)malloc(trimmed_len + 1);
    if (trimmed_str == NULL) {
        return NULL;
    }
    mx_strncpy(trimmed_str, str + start, trimmed_len);
    trimmed_str[trimmed_len] = '\0';

    return trimmed_str;
}

