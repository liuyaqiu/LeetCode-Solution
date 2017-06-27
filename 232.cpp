#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(NULL) {}
};

class Stack {
    private:
        Node* head;
        int n;

    public:
        Stack(): n(0) {
            head = new Node(0);
        };

        bool empty() {
            return n == 0;
        }

        int size() {
            return n;
        }

        void push(int x) {
            Node* cur = new Node(x);
            cur->next = head->next;
            head->next = cur;
            n++;
        }

        int top() {
            return head->next->val;
        }

        void pop() {
            if(empty())
                return;
            Node* cur = head->next;
            head->next = cur->next;
            delete(cur);
            n--;
        }
};

class MyQueue {
    private:
        Stack stk1;
        Stack stk2;
        int n;

    public:
        MyQueue(): n(0) {
            stk1 = Stack();
            stk2 = Stack();
        }

        bool empty() {
            return n == 0;
        }

        void push(int x) {
            stk1.push(x);
            n++;
        }

        int pop() {
            int top = peek();
            stk2.pop();
            return top;
        }

        int peek() {
            if(stk2.empty()) {
                while(!stk1.empty()) {
                    int tmp = stk1.top();
                    stk1.pop();
                    stk2.push(tmp);
                }
            }
            int top = stk2.top();
            return top;
        }
};

