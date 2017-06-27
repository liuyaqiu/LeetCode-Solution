#include <iostream>
#include <vector>
#include <random>

using namespace std;

/*
 * Linked List Random Node
 *
 * Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
 *
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?
 *
 *
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {};
};

class Solution {
private:
    ListNode* list;
    ListNode* cur;
    default_random_engine generator;
    uniform_int_distribution<int> distribution;
    int n;

    void move() {
        int k = distribution(generator);
        while(k > 0) {
            if(cur->next == NULL)
                cur = list;
            else
                cur = cur->next;
        }
    }

public:
    Solution(ListNode* head): list(head), cur(head) {
        ListNode* tmp = list;
        n = 0;
        while(tmp != NULL) {
            tmp = tmp->next;
            n += 1;
        }
        distribution = uniform_int_distribution<int>(1, n);
    }

    int getRandom() {
        int res = cur->val;
        move();
        return res;
    }
};

