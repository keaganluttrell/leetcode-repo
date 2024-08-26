// #include "hashmaps.h"
#include <stdio.h>
// #include <stdlib.h>

#include "hashmaps.h"

int main(int argc, char *argv[]) {

    char *s1[] = {"abcabcbb", "bbbbb", "pwwkew", "", "a", "au"};
    int expected[] = {3, 1, 3, 0, 1, 2};
    int actual;

    for (int i = 0; i < 6; ++i) {
        actual = lengthOfLongestSubstring(s1[i]);
        printf("e: %d, a: %d\n", expected[i], actual);
    }

    return 0;
}
