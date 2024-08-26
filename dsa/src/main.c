// #include "hashmaps.h"
#include <stdio.h>
// #include <stdlib.h>

#include "hashmaps.h"

int main(int argc, char *argv[]) {

    char *s1[] = {"aA", "z"};
    char *s2[] = {"aAAbbb", "ZZ"};
    int expected[] = {3, 0};
    int actual;

    for (int i = 0; i < 2; ++i) {
        actual = numJewelsInStones(s1[i], s2[i]);
        printf("e: %d, a: %d\n", expected[i], actual);
    }

    return 0;
}
