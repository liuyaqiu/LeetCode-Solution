#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {};
};

ListNode* rotateRight(ListNode* head, int k) {
    int len = 0;
    ListNode* p = head;
    ListNode* tail = head;
    while(p != NULL) {
        if(p->next == NULL)
            tail = p;
        p = p->next;
        len += 1;
    }
    if(len <= 1 || k % len == 0)
    	return head;
    int n = (len - k % len);
    int i = 1;
    ListNode* cur = head;
    while(i != n) {
        cur = cur->next;
        i += 1;
    }
    ListNode* head2 = cur->next;
    tail->next = head;
    cur->next = NULL;
    return head2;
}

void print(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Please input the number: ";
    cin >> n;
    int val;
    ListNode* pre = NULL; 
    ListNode* head;
    while(n > 0) {
        cin >> val;
        ListNode* cur = new ListNode(val);
        if(pre == NULL) {
            pre = cur;
            head = cur;
        }
        else
            pre->next = cur;
        pre = cur;
        n -= 1;
    }
    print(head);
    int k;
    cout << "Input the k: ";
    cin >> k;
    ListNode* rotate = rotateRight(head, k);
    print(rotate);
    return 0;
}
