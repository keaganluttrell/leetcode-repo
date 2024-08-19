/*
 * Process for problem solving
 *
 * Clarify the problem: Reverse the string
 *
 * Define the Problem: given a string and its size,
 * reverse the string in place
 *
 * Constraints: reverse the sting in place
 *  -> String Size 1<= string sz <= 10^5
 *  -> each char is a printable ascii char
 *
 * Inputs: string_ptr and int sz
 *
 * Outputs: void, side effect is that the string changes in place
 *
 * Edge Cases:
 *  -> Empty string?
 *
 * Come up with a solution in pseudocode
 *
 * Solve the problem
 *
 * Analyze Performance
 *
 * Refactor to Optimal Solution
 */
#include <stdio.h>

#include "reverse-string.h"

void reverse_string(char *s, int sz) {
    printf("sz %d\n", sz);

    if (sz < 2)
        return;

    int left = 0;
    int right = sz - 1;

    while (left < right) {
        // swap pointers
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}
