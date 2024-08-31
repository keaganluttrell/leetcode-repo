#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stacks.h"

int main(int argc, char *argv[]) {

    char *arr[][2] = {
        {"", ""},     {"s", "s"},   {"xX", ""},     {"Yy", ""},
        {"zz", "zz"}, {"QQ", "QQ"}, {"abBAcC", ""}, {"leEeetcode", "leetcode"},
    };
    int num_test_cases = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < num_test_cases; i++) {
        char *cpy = malloc(strlen(arr[i][0]) + 1);
        strcpy(cpy, arr[i][0]);
        char *actual = makeGood(cpy);
        int equal = strcmp(arr[i][1], actual);
        printf("%s: I: %s -> O: %s E: %s\n", equal == 0 ? "PASS" : "FAIL",
               arr[i][0], actual, arr[i][1]);
        free(cpy);
        free(actual);
    }

    return 0;
}
