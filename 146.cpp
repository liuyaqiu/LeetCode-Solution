#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
    int key;
    int val;
    Node* pre;
    Node* next;
    Node(int k, int v): key(k), val(v), pre(NULL), next(NULL) {}
};

class LRUCache {
private:
    int capacity;
    map<int, Node*> maps;
    Node* head;
    Node* end;

public:
    void print() {
        Node* p = head;
        while(p != NULL) {
            cout << "key = " << p->key << ", value = " << p->val << endl;
            p = p->next;
        }
        cout << endl;
    }

    void remove(Node* p) {
        if(p->pre != NULL)
            p->pre->next = p->next;
        else
            head = p->next;
        if(p->next != NULL)
            p->next->pre = p->pre;
        else
            end = p->pre;
    }

    void setHead(Node* p) {
        p->next = head;
        p->pre = NULL;
        if(head != NULL)
            head->pre = p;
        head = p;
        if(end == NULL)
            end = head;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        end = NULL;
    }

    ~LRUCache() {
        while(head != NULL) {
            Node* cur = head;
            head = head->next;
            delete cur;
        }
    }

    int get(int key) {
        if(maps.find(key) == maps.end())
            return -1;
        Node* p = maps[key];
        remove(p);
        setHead(p);
        return p->val;
    }

    void set(int key, int value) {
        if(maps.find(key) == maps.end()) {
            Node* p = new Node(key, value);
            if(maps.size() == capacity) {
                maps.erase(end->key);
                Node* tmp = end;
                remove(end);
                delete tmp;
                setHead(p);
            }
            else {
                setHead(p);   
            }
            maps[key] = p;
        }
        else {
            Node* p = maps[key];
            p->val = value;
            remove(p);
            setHead(p);
        }
    }
};

int main() {
    int n;
    cin >> n;
     LRUCache lru = LRUCache(n);
    while(true) {
        int cmd;
        cout << "Input cmd: (1) set, (2) get, (3) print: ";
        cin >> cmd;
        if(cmd == 1) {
            int key, val;
            cout << "Input key and value: ";
            cin >> key >> val;
            lru.set(key, val);
        }
        else if(cmd == 2){
            int key;
            cout << "Input key: ";
            cin >> key;
            cout << "The value is: " << lru.get(key) << endl;
        }
        else {
            lru.print();
        }
    }
    return 0;
}
