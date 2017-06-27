#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

void reverse(ListNode* &head) {
	ListNode* pre = NULL;
	ListNode* cur = head;
	while(cur != NULL) {
		ListNode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	head = pre;
}

ListNode* half(ListNode* head) {
	ListNode* first = head;
	ListNode* second = head;
	ListNode* pre = first;
	while(second != NULL) {
		pre = first;
		first = first->next;
		second = second->next;
		if(second != NULL)
			second = second->next;
		else
			break;
	}
	pre->next = NULL;
	return first;
}

ListNode* reorderList(ListNode* head) {
	if(head == NULL)
		return NULL;
	ListNode* first = head;
	ListNode* second = half(head);
	reverse(second);
	while(first != NULL && second != NULL) {
		ListNode* tmp_first = first->next;
		ListNode* tmp_second = second->next;
		first->next = second;
		second->next = tmp_first;
		first = tmp_first;
		second = tmp_second;
	}
	return head;
}

int main() {
    vector<ListNode*> list;
    int val;
    while(cin >> val) {
        ListNode* cur = new ListNode(val);
        list.push_back(cur);
    }
    ListNode* head = list[0];   
    for(auto iter = list.begin(); iter != list.end() - 1; iter++)
        (*iter)->next = *(iter + 1);
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    head = list[0];
    cout << endl;
    head = reorderList(head); 
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
