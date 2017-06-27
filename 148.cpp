#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
    ListNode* p = head;
    while(p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

ListNode* genList(int n) {
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    int val;
    while(n > 0) {
        n -= 1;
        cin >> val;
        ListNode* cur = new ListNode(val);
        pre->next = cur;
        pre = cur;
    }
    return head->next;
}

ListNode* getTail(ListNode* head) {
    if(head == NULL)
        return NULL;
    ListNode* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}

ListNode* merge(ListNode* pre_head, ListNode* next_head, ListNode* first, ListNode* second) {
    ListNode* tmp = new ListNode(0);
    ListNode* res = tmp;
    ListNode* flag = second;
    while(first != flag && second != next_head) {
        if(first->val < second->val) {
            tmp->next = first;
            first = first->next;
        }
        else {
            tmp->next = second;
            second = second->next;
        }
        tmp = tmp->next;
    }
    if(first != flag) {
        tmp->next = first;
        while(first->next != flag) {
            first = first->next;
        }
        first->next = next_head;
    }
    if(second != next_head) {
        tmp->next = second;
    }
    pre_head->next = res->next;
    return res->next;
}
    
ListNode* sortList(ListNode* head) {
    int h = 1;
    ListNode* res = new ListNode(0);
    res->next = head;
    while(true) {
        print(res->next);
        ListNode* pre_head = res;
        ListNode* first = res->next;
        ListNode* second = first;
        for(int i = 0; i < h && second != NULL; i++) {
            second = second->next;
        }
        if(second == NULL)
            break;
        ListNode* next_head = second;
        for(int i = 0; i < h && next_head != NULL; i++) {
            next_head = next_head->next;
        }
        merge(pre_head, next_head, first, second);
        while(next_head != NULL) {
            while(pre_head->next != next_head)
                pre_head = pre_head->next;
            first = next_head;
            second = first;
            for(int i = 0; i < h && second != NULL; i++) {
                second = second->next;
            }
            next_head = second;
            for(int i = 0; i < h && next_head != NULL; i++) {
                next_head = next_head->next;
            }
            merge(pre_head, next_head, first, second);
            print(res->next);
        }
        h = h * 2;
    }
    return res->next;
}

int main() {
    int n;
    cin >> n;
    ListNode* first = genList(n);
    ListNode* tail1 = getTail(first);
    print(first);
    cin >> n;
    ListNode* second = genList(n);
    ListNode* tail2 = getTail(second);
    print(second);
    tail1->next = second;
    ListNode* third = new ListNode(-1);
    tail2->next = third;
    //first = merge(first->next->next, first, first->next);
    //print(first);
    ListNode* res = sortList(first);
    print(res);
    return 0;
}
