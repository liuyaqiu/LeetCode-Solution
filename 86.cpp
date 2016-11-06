#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* less = new ListNode(0);
    ListNode* res = less;
    ListNode* great = new ListNode(0);
    ListNode* tmp = great;
    while(head != NULL) {
        if(head->val < x) {
            less->next = head;
            less = head;
        }
        else {
            great->next = head;
            great = head;
        }
        head = head->next;
        if(head == NULL)
            great->next = NULL;
    }
    less->next = tmp->next;
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
    int n;
    cout << "Please input n: ";
    cin >> n;
    int val;
    ListNode* head = new ListNode(0);
    ListNode* list = head;
    for(int i = 0; i < n; ++i) {
        cin >> val;
        ListNode* cur = new ListNode(val);
        head->next = cur;
        head = cur;
    }
    print(list->next);
    int k;
    cout << "Please input k: ";
    cin >> k;
    ListNode* par = partition(list->next, k);
    print(par);
    return 0;
}
