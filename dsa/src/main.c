#include <stdio.h>
#include <stdlib.h>

#include "linked-lists.h"

int main(int argc, char *argv[]) {

    struct ListNode head;
    struct ListNode *actual;
    head.val = 0;
    head.next = NULL;

    printf("i: 0 -- head\n");

    struct ListNode *curr = &head;
    for (int i = 1; i < 7; i++) {

        struct ListNode *node =
            (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = i;
        node->next = NULL;
        curr->next = node;
        curr = curr->next;

        actual = middleNode(&head);
        if (actual == NULL) {
            printf("Err: actual is null\n");
            return 1;
        } else {
            printf("i: %d -- actual %d\n", i, actual->val);
        }
    }

    return 0;
}
