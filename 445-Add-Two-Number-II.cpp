#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* reverse(ListNode* list) {
    ListNode* pre = NULL;
    ListNode* cur = list;
    while(cur != NULL) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int len(ListNode* list) {
    int n = 0;
    while(list != NULL) {
        n++;
        list = list->next;
    }
    return n;
}

ListNode* carry(ListNode* head) {
    ListNode* rev = reverse(head);
    ListNode* cur = rev;
    while(cur->next != NULL) {
        int val = cur->val;
        if(val >= 10) {
            cur->val = val % 10;
            cur->next->val += val / 10;
        }
        cur = cur->next;
    }
    if(cur->val >= 10) {
        int val = cur->val;
        cur->val = val % 10;
        ListNode* tmp = new ListNode(val / 10);
        cur->next = tmp;
    }
    ListNode* result = reverse(rev);
    return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int n1 = len(l1), n2 = len(l2);
    if(n1 < n2)
        swap(l1, l2);
    n1 = len(l1), n2 = len(l2);
    ListNode* head = new ListNode(0);
    ListNode* res = head;
    int pos = 0;
    while(pos < n1 - n2) {
        ListNode* tmp = new ListNode(l1->val);
        head->next = tmp;
        head = tmp;
        l1 = l1->next;
        pos++;
    }
    while(pos < n1) {
        ListNode* tmp = new ListNode(l1->val + l2->val);
        head->next = tmp;
        head = tmp;
        l1 = l1->next;
        l2 = l2->next;
        pos++;
    }
    return carry(res->next);
}

int main() {
    int val;
    int m, n;
    cin >> m;
    ListNode* h1 = new ListNode(0);
    ListNode* l1 = h1;
    for(int i = 0; i < m; i++) {
        cin >> val;
        ListNode* tmp = new ListNode(val);
        h1->next = tmp;
        h1 = tmp;
    }
    l1 = l1->next;
    ListNode* h2 = new ListNode(0);
    ListNode* l2 = h2;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> val;
        ListNode* tmp = new ListNode(val);
        h2->next = tmp;
        h2 = tmp;
    }
    l2 = l2->next;
    print(l1);
    print(l2);
    ListNode* res = addTwoNumbers(l1, l2);
    print(res);
    return 0;
}
