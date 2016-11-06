#include <iostream>
#include <string>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
} *List;

List removeNthFromEnd(List head, int n) {
    ListNode* res = head;
    ListNode* pre = head;
    ListNode* cur = head;
    while(n >= 0 && cur != NULL) {
        cur = cur->next;
        n -= 1;
    }
    if(n >= 0) {
        res = head->next;
        free(head);
        return res;
    }
    while(cur != NULL) {
        cur = cur->next;
        pre = pre->next;
    }
    ListNode* q = pre->next;
    pre->next = q->next;
    free(q);
    return res;
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

void pirntLinkList(List link) {
    ListNode* cur = link;
    while(cur != NULL) {
        cout << cur-> val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    List link = getLinkList();
    cout << "The LinkList is:" << endl;
    pirntLinkList(link);
    int num = 5;
    List rev = removeNthFromEnd(link, num);
    cout << "The res linklist is:" << endl;
    pirntLinkList(rev);
    return 0;
}

