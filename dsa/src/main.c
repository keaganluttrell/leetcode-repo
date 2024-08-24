// #include "hashmaps.h"
#include <stdio.h>
// #include <stdlib.h>

#include "hashmaps.h"
int main(int argc, char *argv[]) {

    char *text = "nlaebolko";
    int expected = 1;
    int actual = maxNumberOfBalloons(text);

    printf("e: %d, a: %d\n", expected, actual);

    char *text2 = "loonbalxballpoon";
    int expected2 = 2;
    int actual2 = maxNumberOfBalloons(text2);

    printf("e: %d, a: %d\n", expected2, actual2);

    char *text3 = "leetcode";
    int expected3 = 0;
    int actual3 = maxNumberOfBalloons(text3);

    printf("e: %d, a: %d\n", expected3, actual3);

    return 0;
}
