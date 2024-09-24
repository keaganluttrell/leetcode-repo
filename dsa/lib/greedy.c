#include "greedy.h"

#include <stdio.h>

int maximum69Number(int num) {
    int start, digit, n;

    start = 1000;
    while (start > num) {
        start /= 10;
    }

    n = num;
    while (start > 0) {
        digit = n / start;
        n = n % start;
        if (digit == 6) {
            return num + (3 * start);
        }
        start /= 10;
    }

    return num;
}
