
#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *middleNode(struct ListNode *head);
#endif
