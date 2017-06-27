#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Queue {
    private:
        int n;
        ListNode* head;
        ListNode* tail;
    
    public:
        Queue(): n(0), head(NULL), tail(NULL) {};

        int size() {
            return n;
        }

        bool empty() {
            return n == 0;
        }

        void push(int x) {
            ListNode* cur = new ListNode(x);
            if(tail == NULL) {
                head = cur;
                tail = cur;
            }
            else {
                tail->next = cur;
                tail = cur;
            }
            n += 1;
        }

        void pop() {
            if(empty())
                return;
            ListNode* tmp = head;
            ListNode* cur = head->next;
            if(cur == NULL) {
                head = NULL;
                tail = NULL;
            }
            else
                head = cur;
            delete(tmp);
            n -= 1;
        }

        int top() {
            if(empty())
                return -1;
            else
                return head->val;
        }
};

class MyStack {
    private:
        Queue qa;
        Queue qb;

    public:
        MyStack() {
        }

        void push(int x) {
            qb.push(x);
            while(!qa.empty()) {
                int top = qa.top();
                qa.pop();
                qb.push(top);
            }
            Queue tmp = qa;
            qa = qb;
            qb = tmp;
        }

        int top() {
            return qa.top();
        }

        int pop() {
            int res = qa.top();
            qa.pop();
            return res;
        }

        bool empty() {
            return qa.empty();
        }
};

