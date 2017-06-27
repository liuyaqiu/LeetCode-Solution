#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

int length(ListNode* headA) {
    int len = 0;
    while(headA != NULL) {
        headA = headA->next;
        len += 1;
    }
    return len;
}

void swap(ListNode* &h1, ListNode* &h2) {
    ListNode* tmp = h2;
    h2 = h1;
    h1 = tmp;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = length(headA);
    int lenB = length(headB);
    int delta = abs(lenA - lenB);
    ListNode *h1 = headA, *h2 = headB;
    if(lenA > lenB)
        swap(h1, h2);
    while(delta > 0) {
        h2 = h2->next;
        delta--;
    }
    while(h1 != NULL && h2 != NULL && h1 != h2) {
        h1 = h1->next;
        h2 = h2->next;
    }
    if(h1 == NULL || h2 == NULL)
        return NULL;
    else
        return h1;
}
