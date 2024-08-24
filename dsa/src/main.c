// #include "hashmaps.h"
#include <stdio.h>
// #include <stdlib.h>

#include "hashmaps.h"
int main(int argc, char *argv[]) {

    int nums[] = {5, 7, 3, 9, 4, 9, 8, 3, 1};
    int expected = 8;
    int actual = largestUniqueNumber(nums, 9);

    printf("e: %d, a: %d\n", expected, actual);
    return 0;
}
