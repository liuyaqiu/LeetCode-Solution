/*
 * Merge k Sorted Lists
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    ListNode *first, *second;
    if(l1->val < l2->val) {
        first = l1;
        second = l2;
    }
    else {
        first = l2;
        second = l1;
    }
    ListNode* res = first;
    while(first != NULL && second != NULL) {
        ListNode* pre = first;
        while(first != NULL && first->val <= second->val) {
            pre = first;
            first = first->next;
        }
        pre->next = second;
        ListNode* tmp = first;
        first = second;
        second = tmp;
    }
    return res;
}

vector<ListNode*> merge(vector<ListNode*> lists) {
    vector<ListNode*> res;
    for(auto iter = lists.begin(); iter != lists.end(); iter += 2) {
        if(iter == lists.end() - 1) {
            res.push_back(*iter);
            break;
        }
        else
            res.push_back(mergeTwoLists(*iter, *(iter + 1)));
    }
    return res;
}

ListNode* mergeKLists(vector<ListNode*> lists) {
    vector<ListNode*> res = merge(lists);
    while(res.size() > 1)
        res = merge(res);
    if(res.empty())
        return NULL;
    else
        return res.front();
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

