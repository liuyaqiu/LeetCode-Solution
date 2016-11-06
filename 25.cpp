#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	pre->val = 0;
	pre->next = NULL;
	ListNode* res = pre;
    while(head != NULL) {
        stack<ListNode*> stk;
        ListNode* tmp = head;
        for(int i = 0; i < k; i += 1) {
            stk.push(head);
            head = head->next;
            if(head == NULL && i < k - 1) {
		        pre->next = tmp;
		        return res->next;
        	}
        }
        while(!stk.empty()) {
            ListNode* cur = stk.top();
            pre->next = cur;
            pre = cur;
            stk.pop();
        }
        if(head == NULL) {
        	pre->next = NULL;
        	return res->next;
        }
    }
    return res->next;
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

void pirntLinkList(ListNode* link) {
    ListNode* cur = link;
    while(cur != NULL) {
        cout << cur-> val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    ListNode* list = getLinkList();
    cout << "The list is: " << endl;
    pirntLinkList(list);
    int k = 3;
    cout << "The reverse k group list is: " << endl;
    pirntLinkList(reverseKGroup(list, k));
    return 0;
}
