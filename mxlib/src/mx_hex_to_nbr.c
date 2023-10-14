#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long answer = 0;
    int i = 0;

    while(hex[i] != '\0') {
        if (hex[i] >= '0' && hex[i] <= '9') {
            answer = answer * 16 + (hex[i] - '0');
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            answer = answer * 16 + (hex[i] - 'A' + 10);
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            answer = answer * 16 + (hex[i] - 'a' + 10);
        }
        i++;
    }

    return answer;
}

