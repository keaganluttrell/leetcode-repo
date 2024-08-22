#include "hashmaps.h"
#include <stdio.h>
#include <string.h>
#include <uthash.h>

/*
 * Define the Problem: Given a string, determine if every letter
 * in the english alphabet is used at least once. This is called a
 * Pangram
 *
 * Constraints:
 * 1 <= string_length <= 1000
 * sentence consists of lowercase english letters
 *
 * Inputs: string
 *
 * Outputs: boolean
 *
 * Edge Cases:
 *  If string < english alphabet size or 26
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 *
 * implement a set, when set is alpabet char and set length
 * equals alphabet_sz, return true.
 *
 * implement a hash map, for each char, find the char in the
 * map and set a flag stating it was used. if any letter is
 * unused return false. with this method, i have to iterate
 * over the keys.. unless, i am keeping track of length, like
 * with the set.
 *
 * overall set seems simpler.
 *
 */
bool checkIfPangram(char *sentence) {
    char a[26] = {0};
    short c = 0;
    int len = strlen(sentence);

    for (int i = 0; i < len; i++) {
        if (a[sentence[i] - 'a'] == 0) {
            a[sentence[i] - 'a']++;
            c++;
        }
    }

    return c == 26;
}

/*
 * Define the Problem: Given an int array, containing 'n'
 * distinct numbers in range [0,n] return only the number
 * that is missing from the array.
 *
 * Constraints:
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * All numbers of nums are unique
 *
 * Inputs: int array, int array_sz
 *
 * Outputs: int (number missing from range)
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
int missingNumber(int *nums, int numsSize) { return 0; }
