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
