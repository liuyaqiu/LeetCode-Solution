#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && slow != NULL) {
        slow = slow->next;
        if(slow == NULL)
            break;
        fast = fast->next;
        if(fast == NULL)
            break;
        else
            fast = fast->next;
        if(fast == slow)
            break;
    }
    if(fast == NULL || slow == NULL)
        return NULL;
    ListNode* tmp = slow->next;
    int c = 1;
    while(tmp != slow) {
        c += 1;
        tmp = tmp->next;
    }
    ListNode* first = head;
    ListNode* second = head;
    for(int i = 0; i < c; i++)
        first = first->next;
    while(first != second) {
        first = first->next;
        second = second->next;
    }
    return first;
}
