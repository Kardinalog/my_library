#include "libmx.h"

int mx_sqrt(int x) {
    if (x >= 1) {
        int c = 1;

        while (x > c * c) {
            c++;
        }

        if (c * c == x) {
            return c;
        }
    }
    return 0;
}
