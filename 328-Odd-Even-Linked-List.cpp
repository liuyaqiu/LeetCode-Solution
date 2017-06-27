#include <iostream>
#include <vector>

using namespace std;

/*
 * Odd Even Linked List
 *
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 *
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 *
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input. 
 * The first node is considered odd, the second node even and so on ...
 *
 *
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    int cnt = 1;
    ListNode* odd = new ListNode(0);
    ListNode* even = new ListNode(0);
    ListNode* ostart = odd;
    ListNode* estart = even;
    while(head != NULL) {
        if(cnt % 2 == 1) {
            odd->next = head;
            odd = head;
        }
        else {
            even->next = head;
            even = head;
        }
        head = head->next;
        cnt++;
    }
    even->next = NULL;
    odd->next = estart->next;
    return ostart->next;
}

void print(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int val;
    ListNode* head = new ListNode(0);
    ListNode* start = head;
    while(cin >> val) {
        ListNode* tmp = new ListNode(val);
        head->next = tmp;
        head = tmp;
    }
    print(start->next);
    ListNode* res = oddEvenList(start->next);
    print(res);
    return 0;
}
