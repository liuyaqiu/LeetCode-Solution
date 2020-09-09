/*
 * Reverse Nodes in k-Group
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 */

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
