#include <stdio.h>
#include <stdlib.h>

#include "linked-lists.h"

int main(int argc, char *argv[]) {

    struct ListNode *head;
    struct ListNode *actual;
    struct ListNode *expected;

    int arr[5] = {1, 2, 3, 4, 5};
    int exp[5] = {1, 4, 3, 2, 5};

    head = array_to_list(arr, 5);
    actual = array_to_list(arr, 5);
    expected = array_to_list(exp, 5);
    print_list(head, "original");

    actual = reverseBetween(actual, 2, 4);
    if (actual == NULL) {
        printf("actual is null\n");
    } else {
        print_list(expected, "expected");
        print_list(actual, "actual  ");
    }

    return 0;
}
