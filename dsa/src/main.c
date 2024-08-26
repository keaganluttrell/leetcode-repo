// #include "hashmaps.h"
#include <stdio.h>
// #include <stdlib.h>

#include "hashmaps.h"

int main(int argc, char *argv[]) {

    char *notes[] = {"a", "aa", "aa"};
    char *magazines[] = {"b", "ab", "aab"};
    bool expected[] = {false, false, true};
    bool actual;

    for (int i = 0; i < 3; ++i) {
        actual = canConstruct(notes[i], magazines[i]);
        printf("e: %d, a: %d\n", expected[i], actual);
    }

    return 0;
}
