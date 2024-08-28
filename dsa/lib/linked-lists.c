#include <stdio.h>
// #include <stdlib.h>
#include "linked-lists.h"

/*
 * Define the Problem: Given the head of a singly linked
 * list, return the middle node of the linked list.
 * If there are two, return the second middle ndoe.
 *
 * Constraints: nodes range [1,100]
 * node value is [1,100]
 *
 * Inputs: head of a linked list.
 *
 * Outputs: middle node of linked list.
 *
 * Edge Cases: single node list, return head?
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */

struct ListNode *middleNode(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
