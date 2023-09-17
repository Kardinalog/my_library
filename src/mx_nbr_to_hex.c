#include "libmx.h"

char* mx_nbr_to_hex(unsigned long nbr) {
    int nbrcopy = nbr;
    int len = 0, r = 0;

    while (nbr != 0) {
        r = nbr % 16;
        nbr /= 16;
        len++;
    }

    if (len == 0) {
        return 0;
    }
    char* h = mx_strnew(len);

    for (int i = len - 1; i >= 0; i--) {
        r = nbrcopy % 16;
        if (r < 10) {
            h[i] = r + 48;
        }
        else {
            h[i] = r + 32 + 55;
        }
        nbrcopy /= 16;
    }

    return h;
}
