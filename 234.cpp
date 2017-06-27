#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* half(ListNode* head) {
    ListNode* high = head;
    ListNode* low = head;
    while(high != NULL) {
        high = high->next;
        if(high == NULL)
            break;
        else
            high = high->next;
        low = low->next;
    }
    return low;
}

bool isPalindrome(ListNode* head) {
    if(head == NULL)
        return true;
    ListNode* mid = half(head);
    ListNode* pre = mid;
    ListNode* cur = pre->next;
    pre->next = NULL;
    while(cur != NULL) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    ListNode* start = head;
    ListNode* end = pre;
    while(end != NULL && start != end) {
        if(start->val != end->val)
            return false;
        start = start->next;
        end = end->next;
    }
    return true;
}

int main() {
    int val;
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    while(cin >> val) {
        ListNode* tmp = new ListNode(val);
        cur->next = tmp;
        cur = tmp;
    }
    ListNode* test = head->next;
    bool res = isPalindrome(test);
    cout << res << endl;
    return 0;
}
