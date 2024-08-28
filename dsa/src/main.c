#include <stdio.h>
#include <stdlib.h>

#include "linked-lists.h"

int main(int argc, char *argv[]) {

    struct ListNode *head;
    struct ListNode *actual;
    struct ListNode *expected;

    int arr[9] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    int exp[3] = {1, 2, 3};

    head = array_to_list(arr, 9);
    actual = array_to_list(arr, 9);
    expected = array_to_list(exp, 3);
    print_list(head, "original");

    actual = deleteDuplicates(actual);
    if (actual == NULL) {
        printf("actual is null\n");
    } else {
        print_list(expected, "expected");
        print_list(actual, "actual  ");
    }

    return 0;
}
