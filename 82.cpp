#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL) {};
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* p = head;
    ListNode* res = new ListNode(0);
    ListNode* q = res;
    while(p != NULL) {
        int tmp = p->val;
        if(p->next == NULL || p->next->val != tmp) {
            res->next = p;
            res = p;
            p = p->next;
        }
        else {
            ListNode* t = p->next;
            while(t != NULL && t->val == tmp) {
                t = t->next;
            }
            if(t == NULL)
            	res->next = t;
            p = t;
        }
    }
    return q->next;
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
    cout << "Please input n: ";
    cin >> n;
    ListNode* head = new ListNode(0);
    ListNode* res = head;
    int val;
    for(int i = 0; i < n; ++i) {
        cin >> val;
        ListNode* tmp = new ListNode(val);
        head->next = tmp;
        head = tmp;
    }
    print(res->next);
    ListNode* get = deleteDuplicates(res->next);
    print(get);
    return 0;
}
