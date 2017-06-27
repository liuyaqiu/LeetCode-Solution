#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
    ListNode* p = head;
    while(p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void insert(ListNode* head, ListNode* &cur) {
    ListNode* pre = head;
    ListNode* tmp = head->next;
    while(tmp != NULL && tmp->val < cur->val) {
        pre = tmp;
        tmp = tmp->next;
    }
    ListNode* q = cur->next;
    pre->next = cur;
    cur->next = tmp;
    cur = q;
}

ListNode* insertionSortList(ListNode* head) {
    ListNode* res = new ListNode(0);
    while(head != NULL) {
        insert(res, head);
    }
    return res->next;
}

int main() {
    ListNode* head = new ListNode(0);
    int val;
    ListNode* pre = head;
    while(cin >> val) {
        ListNode* cur = new ListNode(val);
        pre->next  = cur;
        pre = cur;
    }
    print(head->next);
    ListNode* res = insertionSortList(head->next);
    print(res);
    return 0;
}
