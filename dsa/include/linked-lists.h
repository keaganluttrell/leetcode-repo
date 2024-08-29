
#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H
struct ListNode {
    int val;
    struct ListNode *next;
};
void print_list(struct ListNode *head, char *list_name);
struct ListNode *array_to_list(int *array, int sz);
struct ListNode *reverse_list(struct ListNode *head);
struct ListNode *middleNode(struct ListNode *head);
struct ListNode *deleteDuplicates(struct ListNode *head);
struct ListNode *reverseBetween(struct ListNode *head, int left, int right);
#endif
