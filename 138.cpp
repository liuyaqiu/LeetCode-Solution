#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL) {}
};

struct cmp {
    bool operator() (const RandomListNode* p, const RandomListNode* q) const {
        return p->label < q->label;
    }
};

RandomListNode* copyRandomList(RandomListNode* head) {
    if(head == NULL)
        return NULL;
    map<RandomListNode*, RandomListNode*, cmp> refer;
    RandomListNode* p = head;
    while(p != NULL) {
        RandomListNode* cur = new RandomListNode(p->label);
        refer[p] = cur;
        p = p->next;
    }
    RandomListNode* old = head;
    RandomListNode* q = refer[old];
    while(old != NULL) {
        if(old->next != NULL)
            q->next = refer[old->next];
        if(old->random != NULL)
            q->random = refer[old->random];
        old = old->next;
        if(old != NULL)
            q = refer[old];
        else
            q = NULL;
    }
    return refer[head];
}

void print(RandomListNode* head) {
    while(head != NULL) {
        cout << head->label<< " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int val;
    RandomListNode* head = new RandomListNode(0);
    RandomListNode* pre = head;
    while(cin >> val) {
        RandomListNode* tmp = new RandomListNode(val);
        pre->next = tmp;
        pre = tmp;
    }
    print(head->next);
    RandomListNode* res = copyRandomList(head->next);
    print(res);
}
