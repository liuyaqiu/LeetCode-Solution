#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
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
            return true;
    }
    return false;
}
