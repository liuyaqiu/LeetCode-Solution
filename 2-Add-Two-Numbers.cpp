/*
 * Add Two Numbers
 *
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 */

#include <iostream>
#include <vector>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* prep;
        ListNode* preq;
        int tmp = 0;
        while(p != NULL && q != NULL){
            p->val += tmp + q->val;
            if(p->val >= 10){
                tmp = 1;
                p->val -= 10;
            }
            else
                tmp = 0;
            prep = p;
            preq = q;
            p = p->next;
            q = q->next;
        }
        if(p == NULL){
            prep->next = q;
            p = prep->next;
        }
        while(tmp != 0 and p != NULL){
            p->val += tmp;
            if(p->val >= 10){
                tmp = 1;
                p->val -= 10;
            }
            else
                tmp = 0;
            prep = p;
            p = p->next;
        }
        if(tmp > 0){
            ListNode* res = new ListNode(tmp);
            prep->next = res;
        }
        return l1;
    }
};
