#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    int val;
    int min;
    Node* next;
    Node(int x, int m): val(x), min(m), next(NULL) {}
};

class MinStack {
private:
    Node* head;
    Node* toph;
public:
    MinStack() {
        head = new Node(0, 0);
        toph = head->next;
    }

    void push(int x) {
        int m = x;
        if(toph != NULL)
            m = min(x, toph->min);
        Node* tmp = new Node(x, m);
        tmp->next = toph;
        head->next = tmp;
        toph = head->next;
    }

    void pop() {
        if(toph == NULL)
            return;
        head->next = toph->next;
        Node* p = toph;
        toph = head->next;
        delete(p);
    }

    int top() {
        if(toph == NULL)
            return -1;
        else
            return toph->val;
    }

    int getMin() {
        return toph->min;
    }
};


int main() {
    MinStack obj = MinStack();
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << obj.getMin() << endl;
    obj.pop();
    cout << obj.top() << endl;
    obj.push(-4);
    cout << obj.top() << endl;
    cout << obj.getMin() << endl;
    return 0;
}
