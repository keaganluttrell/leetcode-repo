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

/*
 * Define the Problem: given a 2d int array, where int array i [winner, loser]
 * return a list of size 2, where first list is of all players that have not
 * lost any matches. a list of players that have lost only one match
 *
 * Constraints:
 * 1 < matches.length < 10^5
 * matches[i].length == 2
 * 1 < winner, loser < 10^5
 * winner != loser
 * matches[1] are unique. No rematches.
 *
 * Inputs: Int[N][2];
 *
 * Outputs: int[2][M];
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */

struct player_entry {
    int id;
    int value;
    UT_hash_handle hh;
};

struct player_entry *p_entry = NULL;

void init_player(int id) {
    struct player_entry *s;

    HASH_FIND_INT(p_entry, &id, s);

    if (s == NULL) {
        s = malloc(sizeof(*s));
        s->id = id;
        s->value = 0;
        HASH_ADD_INT(p_entry, id, s);
    }
}

struct player_entry *find_player(int id) {
    struct player_entry *s;

    HASH_FIND_INT(p_entry, &id, s);
    return s;
}

void add_loss(int id) {
    struct player_entry *s;

    HASH_FIND_INT(p_entry, &id, s);

    if (s != NULL) {
        s->value++;
    }
}

void clean_players() {
    struct player_entry *i, *x;

    HASH_ITER(hh, p_entry, i, x) {
        HASH_DEL(p_entry, i);
        free(i);
    }
}

void insertion_sort(int *arr, int idx) {
    while (idx > 0 && arr[idx] < arr[idx - 1]) {
        if (arr[idx] < arr[idx - 1]) {
            int x = arr[idx];
            arr[idx] = arr[idx - 1];
            arr[idx - 1] = x;
            idx--;
        }
    }
}

int **findWinners(int matches[][2], int matchesSize, int *matchesColSize,
                  int *returnSize, int **returnColumnSizes) {

    *returnColumnSizes = (int *)malloc(2 * sizeof(int));
    if (*returnColumnSizes == NULL) {
        return NULL;
    }

    for (int i = 0; i < matchesSize; i++) {
        int winner = matches[i][0];
        int loser = matches[i][1];

        if (find_player(winner) == NULL) {
            init_player(winner);
        }

        if (find_player(loser) == NULL) {
            init_player(loser);
        }

        add_loss(loser);
    }

    struct player_entry *e;
    (*returnColumnSizes)[0] = 0;
    (*returnColumnSizes)[1] = 0;

    for (e = p_entry; e != NULL; e = e->hh.next) {
        if (e->value == 0) {
            (*returnColumnSizes)[0]++;
        } else if (e->value == 1) {
            (*returnColumnSizes)[1]++;
        }
    }

    int **output = (int **)malloc(2 * sizeof(int *));
    output[0] = (int *)malloc((*returnColumnSizes)[0] * sizeof(int));
    output[1] = (int *)malloc((*returnColumnSizes)[1] * sizeof(int));
    if (output[0] == NULL || output[1] == NULL) {
        free(output[0]);
        free(output[1]);
        free(output);
        return NULL;
    }

    int a = 0, b = 0;
    for (e = p_entry; e != NULL; e = e->hh.next) {
        if (e->value == 0) {
            output[0][a] = e->id;
            insertion_sort(output[0], a);
            a++;
        } else if (e->value == 1) {
            output[1][b] = e->id;
            insertion_sort(output[1], b);
            b++;
        }
    }

    *returnSize = 2;
    clean_players();
    return output;
}

/*
 * Define the Problem: Given an integer array nums,
 * return the largest integer that only occurs once.
 *
 * if no integer occurs once, return -1.
 *
 * Constraints:
 * 1< nums.length < 2000
 * 0<nums[i]<=1000
 *
 *
 * Inputs: int array, int sz
 *
 * Outputs: int (-1:1000)
 *
 * Edge Cases:
 *
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */

int largestUniqueNumber(int *nums, int numsSize) {
    unsigned short bucket[1001] = {0};
    for (int i = 0; i < numsSize; ++i)
        ++bucket[nums[i]];
    for (int i = 1000; 0 <= i; --i)
        if (bucket[i] == 1)
            return i;

    return -1;
}

/*
 * Define the Problem: Given a string text, you want to use
 * the characters of text to form as many instances of the
 * word balloon as possible.  You can use each character in
 * text at most once.  Return the max number of instances
 * that can be formed.
 *
 * Constraints:
 * 1<=text.length<= 10^4
 * text is lowercase english letters guaranteed
 *
 * Inputs: string
 *
 * Outputs: int -- max num of instances that can be formed for
 * balloon
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
//
// a = 0;
// b = 1;
// l = 11;
// o = 14;
// n = 13;

int maxNumberOfBalloons(char *text) {
    int letters[26] = {0};
    for (int i = 0; i < strlen(text); ++i) {
        ++letters[text[i] - 'a'];
    }
    // l
    letters[11] /= 2;
    // n
    letters[14] /= 2;

    int min = 10000;

    if (letters[0] < min) {
        min = letters[0];
    }

    if (letters[1] < min) {
        min = letters[1];
    }

    if (letters[11] < min) {
        min = letters[11];
    }

    if (letters[13] < min) {
        min = letters[13];
    }

    if (letters[14] < min) {
        min = letters[14];
    }

    return min;
}

/*
 * Define the Problem: find a contiguos subarray of 0s and 1s
 *
 * Constraints:
 * 1<= nums.length
 * nums[i] == 0 or 1
 *
 * Inputs: Array and size
 *
 * Outputs: int
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 *
 * length can't be max if odd
 * count
 *
 *
 */
int findMaxLength(int *nums, int sz) {
    int arr[sz * 2 + 1];
    for (int i = 0; i < sz * 2 + 1; ++i) {
        arr[i] = -2;
    }

    arr[sz] = -1;
    int max = 0, ct = 0;

    for (int i = 0; i < sz; ++i) {
        nums[i] == 1 ? ct++ : ct--;
        if (arr[ct + sz] >= -1) {
            if ((i - arr[ct + sz]) > max) {
                max = (i - arr[ct + sz]);
            }
        } else {
            arr[ct + sz] = i;
        }
    }

    return max;
}

/*
 * Define the Problem: Confirm if a ransom note can be constructed from a given
 * magazine.
 *
 * Constraints:
 * 1 <= note.len, mag.len <= 10^5
 * note and mag are all lowercase english letters
 *
 * Inputs: string for ransomNote and a string for magazine.
 *
 * Outputs: bool
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */

bool canConstruct(char *ransomNote, char *magazine) {
    int letters[26] = {0};
    int i;

    for (i = 0; i < strlen(ransomNote); ++i) {
        ++letters[ransomNote[i] - 'a'];
    }
    for (i = 0; i < strlen(magazine); ++i) {
        --letters[magazine[i] - 'a'];
    }

    for (i = 0; i < 26; ++i) {
        if (letters[i] > 0) {
            return false;
        }
    }
    return true;
}
