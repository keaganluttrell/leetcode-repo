#include "linked-lists.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(struct ListNode *head, char *list_name) {
    struct ListNode *curr = head;

    printf("%s list: ", list_name);

    while (curr != NULL) {
        if (curr->next == NULL) {
            printf("%d\n", curr->val);
        } else {
            printf("%d -> ", curr->val);
        }
        curr = curr->next;
    }
}

struct ListNode *array_to_list(int *array, int sz) {
    if (sz == 0) {
        return NULL;
    }

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = array[0];
    head->next = NULL;
    struct ListNode *curr = head;

    for (int i = 1; i < sz; ++i) {
        struct ListNode *node =
            (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = array[i];
        node->next = NULL;
        curr->next = node;
        curr = node;
    }
    return head;
}

struct ListNode *reverse_list(struct ListNode *head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr != NULL) {
        struct ListNode *next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
}

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

/*
 * Define the Problem:
 * Gvien the head of a linked list, delate all duplicates such
 * that each element only appears once.
 * Return the list sorted as well.
 *
 * Constraints:
 * Length of list in range of 0 to 300
 * values of -100 to 100
 * the list is guranteed to be sorted in ascending order.
 *
 * Inputs: Head of a linked list
 *
 * Outputs: Head of a linked list
 *
 * Edge Cases: Head is NULL
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *curr = head;
    struct ListNode *tmp;

    while (curr->next != NULL) {
        if (curr->val == curr->next->val) {
            tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
        } else {
            curr = curr->next;
        }
    }

    return head;
}

/*
 * Define the Problem: Given a head of a singly linked list, and two integers
 * right and left, where left <= right, reverse the nodes of the list from
 * left to position right.
 *
 * Constraints:
 * N = number of nodes
 * -500 <= node.val <= 500
 * 1 <= left <= right <= n
 *
 * Inputs: Head of Singly linked list, int left and int right
 *
 * Outputs: head of list
 *
 * Edge Cases:
 * What if the ints are greater than the number of nodes?
 * -- satisfied by the constraints
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    if (left == right || head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode *Left = &dummy;

    for (int i = 1; i < left; ++i) {
        Left = Left->next;
    }

    struct ListNode *curr = Left->next;
    struct ListNode *next_node;

    for (int i = left; i < right; ++i) {
        next_node = curr->next;
        curr->next = next_node->next;
        next_node->next = Left->next;
        Left->next = next_node;
    }

    return dummy.next;
}
