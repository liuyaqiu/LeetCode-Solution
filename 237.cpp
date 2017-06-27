#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
	ListNode* del = node->next;
	node->val = del->val;
	node->next = del->next;
    delete(del);
}
