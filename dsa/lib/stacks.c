#include <stacks.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Define the Problem: Given an absolute path for a Unix
 * style file system, which begins with '/', transform this
 * path into its simplified canonical path.
 *
 *
 * Constraints:
 * Input and output must start with a '/';
 * Directories are separated with a '/';
 * It shoud not end with a '/';
 * Exclude any directory aliases -- ie '.' or '..'
 *
 * 1 <= path.length <= 3000
 * path is english letters, digits, '.', '/', and '_'
 *
 * Inputs: char* path
 *
 * Outputs: char* path
 *
 * Edge Cases:
 * single char string
 * hidden files ie -> /some/path/.env
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */

#define MAX 3000

char *simplifyPath(char *path) {

    char **stack = malloc(strlen(path) * sizeof(char *));
    int top = 0;
    char *token = strtok(path, "/");

    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (top > 0) {
                --top;
            }
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            stack[top++] = token;
        }
        token = strtok(NULL, "/");
    }
    if (top == 0) {
        free(stack);
        char *root = malloc(2);
        strcpy(root, "/");
        return root;
    }

    // Calculate the length of the simplified path
    int length = 0;
    for (int i = 0; i < top; i++) {
        length += strlen(stack[i]) + 1; // +1 for the '/'
    }

    char *simplified = malloc(length + 1);
    simplified[0] = '\0';

    for (int i = 0; i < top; ++i) {
        strcat(simplified, "/");
        strcat(simplified, stack[i]);
    }

    free(stack);

    return simplified;
}

/*
 * Define the Problem: Given a string of
 * lowercase and uppercase english letters
 * return a good string.
 *
 * A good string doesn't have two adject characters where
 * 0 <= i <=len(s) -2
 * s[i] is the lowercase of and s[i+1] is the uppercase of the
 * same letter. remove all such occurences to make a good string.
 *
 * Constraints:
 * 1 <= len(s) <= 100
 * s contains on upper/lower case english letters
 *
 * Inputs: string
 *
 * Outputs: string
 *
 * Edge Cases: empty string, good string.
 *
 * Come up with a solution in pseudocode
 *
 * search the string for adjacent chars
 * identify xX or Xx where
 * x is any english lower case AND
 * X is any english uppercase
 * remove the chars from string.
 *
 * How to ID that x and X are the same english
 * letter of different case? difference in char code.
 *
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 *   stack = "axA"
 *   abBxAcC
 *   ^..^^..i1
 */

char *makeGood(char *s) {
    int s_len = strlen(s);
    int code_diff = 'a' - 'A';
    char *stack = (char *)malloc(s_len + 1);
    int top = -1;

    for (int i = 0; i < s_len; ++i) {
        if (top > -1 && abs(s[i] - stack[top]) == code_diff) {
            top--;
        } else {
            stack[++top] = s[i];
        }
    }
    stack[top + 1] = '\0';
    return stack;
}
