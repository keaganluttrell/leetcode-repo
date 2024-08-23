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
int missingNumber(int *nums, int numsSize) {

    int max = numsSize;
    int i = 0;
    while (i < numsSize) {
        if (nums[i] == numsSize) {
            max = i;
            i++;
        } else if (nums[i] == i) {
            i++;
        } else {
            int x = nums[i];
            nums[i] = nums[x];
            nums[x] = x;
        }
    }
    return max;
}

/*
 * Define the Problem: Given an int array, count how many elements of 'x'
 * there are, such tat x + 1 is also in arr. Count diplicates separately
 *
 * Inputs: Int Array, Int Sz
 *
 * Outputs: Int (count)
 * To increase the counter
 * An element's value + 1 must exist in the array.
 * ex: 1, 2 : 1 + 1 = 2; [1,2]; returns 1
 * ex [1,2,3]: 1+1 = 2, 2 +1 = 3, returns 2
 * ex [0,2,4]; returns 0;
 *
 * Constraints:
 * 1 <= array.length <= 1000
 * 0 < arr[i] <= 1000
 *
 * Edge Cases:
 *  No Negative numbers
 *  No empty arrays;
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 *
 * {1,2,3}
 */

struct map_entry {
    int id;
    int value;
    UT_hash_handle hh;
};

struct map_entry *numbers_entry = NULL;

void add_number(int key, int value) {
    struct map_entry *s;

    HASH_FIND_INT(numbers_entry, &key, s);

    if (s == NULL) {
        s = malloc(sizeof(*s));
        s->id = key;
        s->value = value;
        HASH_ADD_INT(numbers_entry, id, s);
    } else {
        s->value = value;
    }
}

void clean_map() {
    struct map_entry *i, *x;

    HASH_ITER(hh, numbers_entry, i, x) {
        HASH_DEL(numbers_entry, i);
        free(i);
    }
}

struct map_entry *find_number(int id) {
    struct map_entry *s;

    HASH_FIND_INT(numbers_entry, &id, s);
    return s;
}

int countElements(int *arr, int arrSize) {

    int ct = 0;

    for (int i = 0; i < arrSize; i++) {
        add_number(arr[i], 1);
    }

    for (int i = 0; i < arrSize; i++) {
        struct map_entry *e = find_number(arr[i] + 1);
        if (e != NULL) {
            ct++;
        }
    }

    clean_map();
    return ct;
};
