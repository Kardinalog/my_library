#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char utf8[5];
    int bytes_written = 0;

    if (c <= 127) {
        utf8[0] = (char)c;
        bytes_written = 1;
    } else if (c <= 2047) {
        utf8[0] = (char)(192 + (c >> 6));
        utf8[1] = (char)(128 + (c & 63));
        bytes_written = 2;
    } else if (c <= 65535) {
        utf8[0] = (char)(224 + (c >> 12));
        utf8[1] = (char)(128 + ((c >> 6) & 63));
        utf8[2] = (char)(128 + (c & 63));
        bytes_written = 3;
    } else if (c <= 1114111) {
        utf8[0] = (char)(240 + (c >> 18));
        utf8[1] = (char)(128 + ((c >> 12) & 63));
        utf8[2] = (char)(128 + ((c >> 6) & 63));
        utf8[3] = (char)(128 + (c & 63));
        bytes_written = 4;
    }

    write(1, utf8, bytes_written);
}
