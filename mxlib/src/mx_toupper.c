#include "../inc/libmx.h"

char mx_toupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c + ('A' - 'a');
    }
    return c;
}
