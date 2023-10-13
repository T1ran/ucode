#include "../inc/libmx.h"

int mx_isspace(const char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
           c == '\r';
}
