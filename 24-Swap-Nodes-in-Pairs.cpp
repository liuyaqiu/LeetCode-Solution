/*
 * Swap Nodes in Pairs
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* res = head;
    while(head != NULL && head->next != NULL) {
        swap(head->val, head->next->val);
        head = head->next->next;
    }
    return res;
}
