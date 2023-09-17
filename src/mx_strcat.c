#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int count = 0;

    while(*s1) {
	    count++;
	    s1++;
	}

	while(*s2) {
	    count++;
		*s1++ = *s2++;
	}

	*s1 = '\0';
	return s1 - count;
}
