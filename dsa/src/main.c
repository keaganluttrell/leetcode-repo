#include <stdio.h>

#include "reverse-string.h"

int main(int charc, char *argv[]) {

    char test_str1[] = "one";
    char test_str2[] = "dude";

    printf("before\n");
    printf("test_str1: %s\n", test_str1);
    printf("test_str2: %s \n", test_str2);

    reverse_string(test_str1, sizeof(test_str1) - 1);
    reverse_string(test_str2, sizeof(test_str2) - 1);

    printf("after\n");
    printf("test_str1: %s\n", test_str1);
    printf("test_str2: %s \n", test_str2);

    return 0;
}
