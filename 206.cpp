#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
}* LinkList;

ListNode* reverse(LinkList link) {
    ListNode* pre = NULL;
    ListNode* cur = link;
    while(cur != NULL) {
        ListNode* p = cur->next;
        cur->next = pre;
        pre = cur;
        cur = p;
    }
    return pre;
}

ListNode* getLinkList() {
    ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
    int val;
    cin >> val;
    pre->val = val;
    pre->next = NULL;
    ListNode* head = pre;
    while(cin >> val) {
        ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
        cur->val = val;
        cur->next = NULL;
        pre->next = cur;
        pre = cur;
    }
    return head;
}

void pirntLinkList(LinkList link) {
    ListNode* cur = link;
    while(cur != NULL) {
        cout << cur-> val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    LinkList link = getLinkList();
    cout << "The LinkList is:" << endl;
    pirntLinkList(link);
    LinkList rev = reverse(link);
    cout << "The reverse linklist is:" << endl;
    pirntLinkList(rev);
    return 0;
}

