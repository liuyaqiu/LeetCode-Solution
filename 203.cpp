#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* tmp = new ListNode(0);
    tmp->next = head;
    ListNode* pre = tmp;
    ListNode* cur = head;
    while(cur != NULL) {
        if(cur->val == val) {
            ListNode* p = cur;
            pre->next = cur->next;
            cur = cur->next;
            delete(p);
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
    return tmp->next;
}
