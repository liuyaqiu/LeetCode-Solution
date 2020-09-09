/*
 * Merge Two Sorted Lists
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 */

typedef struct ListNode {
    int val;
    ListNode *next;
} ListNode;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    ListNode *first, *second;
    if(l1->val < l2->val) {
        first = l1;
        second = l2;
    }
    else {
        first = l2;
        second = l1;
    }
    ListNode* res = first;
    while(first != NULL && second != NULL) {
        ListNode* pre = first;
        while(first != NULL && first->val <= second->val) {
            pre = first;
            first = first->next;
        }
        pre->next = second;
        ListNode* tmp = first;
        first = second;
        second = tmp;
    }
    return res;
}
