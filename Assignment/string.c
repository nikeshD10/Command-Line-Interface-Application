#include "string.h"

int is_lower(char c) {
    return c>='a' && c<='z';
}

char *str_upr(char *str) {
    char *p = str;
    while (*p != '\0') {
        if (is_lower(*p)) {
            *p = *p - 32;
        }
        p++;
    }
    return str;
}