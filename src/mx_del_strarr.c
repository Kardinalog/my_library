#include "../inc/libmx.h"

void mx_del_strarr(char ***arr) {
    char **a = *arr;

    while (*a){
        free(a++);
    }

    mx_strdel(*arr);
}
