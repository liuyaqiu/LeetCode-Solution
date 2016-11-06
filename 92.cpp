#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* res = new ListNode(0);
    int pos = 1;
    res->next = head;
    ListNode* pre = res;
    while(pos < m) {
        head = head->next;
        pre = pre->next;
        pos += 1;
    }
    ListNode* p = head;
    ListNode* q = p->next;
    while(pos < n) {
        ListNode* tmp = q->next;
        q->next = p;
        p = q;
        q = tmp;
        pos += 1;
    }
    pre->next = p;
    head->next = q;
    return res->next;
}

void print(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int k;
    cout << "Please input k: ";
    cin >> k;
    int val;
    ListNode* list = new ListNode(0);
    ListNode* res = list;
    for(int i = 0; i < k; ++i) {
        cin >> val;
        ListNode* tmp = new ListNode(val);
        list->next = tmp;
        list = list->next;
    }
    ListNode* cur = res->next;
    print(cur);
    int m, n;
    cout << "Input m, n: ";
    cin >> m >> n;
    print(reverseBetween(cur, m, n));
    return 0;
}
