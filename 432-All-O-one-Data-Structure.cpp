#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct KeyNode {
    string key;
    int val;
    KeyNode* pre;
    KeyNode* next;
    KeyNode(string k): key(k), val(1), pre(NULL), next(NULL) {}
};

struct ValueNode {
    int val;
    ValueNode* pre;
    ValueNode* next;
    KeyNode* first;
    ValueNode(KeyNode* key): val(key->val), pre(NULL), next(NULL), first(key) {}
};

class AllOne {
private:
    ValueNode* head;
    ValueNode* tail;
    unordered_map<string, KeyNode*> keyDict;
    unordered_map<int, ValueNode*> valDict;

public:
    AllOne(): head(NULL), tail(NULL) {
        keyDict = unordered_map<string, KeyNode*>();
        valDict = unordered_map<int, ValueNode*>();
    }

    void inc(string key) {
        if(head == NULL) {
            KeyNode* cur = new KeyNode(key);
            ValueNode* value = new ValueNode(cur);
            keyDict[key] = cur;
            valDict[1] = value;
            head = value;
            tail = value;
        }
        else {
            if(keyDict.find(key) != keyDict.end()) {
                int val = keyDict[key]->val;
                KeyNode* cur = keyDict[key];
                KeyNode* prev = cur->pre;
                KeyNode* nx = cur->next;        //修正KeyNode节点
                cur->next = NULL;
                if(prev != NULL)
                    prev->next = nx;
                if(nx != NULL)
                    nx->pre = prev;
                ValueNode* val_nx = valDict[val]->next;
                ValueNode* val_pre = valDict[val];
                cur->val += 1;
                if(valDict[val]->first == cur) {    //如果当前删除的节点是序列中的第一个节点，那么更新first域
                    valDict[val]->first = nx;
                    if(nx == NULL) {
                        ValueNode* v = valDict[val];
                        val_pre = v->pre;    //删除后val域无节点，删除该val节点
                        if(val_pre != NULL)
                            val_pre->next = val_nx;
                        if(val_nx != NULL)
                            val_nx->pre = v->pre;
                        valDict.erase(val);
                        delete(v);
                    }
                }
                if(val_nx == NULL) {
                    ValueNode* vnode = new ValueNode(cur);
                    valDict[vnode->val] = vnode;
                    vnode->pre = val_pre;
                    if(val_pre != NULL)
                        val_pre->next = vnode;
                    else
                        head = vnode;           //更新head域
                    tail = vnode;
                }
                else {
                    if(val_nx->val == cur->val) {
                        KeyNode* start = val_nx->first;
                        start->pre = cur;
                        cur->next = start;
                        val_nx->first = cur;
                        if(val_pre == NULL)   //当前节点已经被删除，前一个节点为空，更新head
                            head = val_nx;  
                    }
                    else {
                        ValueNode* vnode = new ValueNode(cur);
                        valDict[vnode->val] = vnode;
                        vnode->next = val_nx;
                        val_nx->pre = vnode;
                        vnode->pre = val_pre;
                        if(val_pre != NULL)
                            val_pre->next = vnode;
                        else
                            head = vnode;
                    }
                }
            }
            else {
                KeyNode* cur = new KeyNode(key);        //创建新的KeyNode
                keyDict[key] = cur;
                if(valDict.find(1) != valDict.end()) {
                    KeyNode* tmp = valDict[1]->first;
                    tmp->pre = cur;
                    cur->next = tmp;
                    valDict[1]->first = cur;
                }
                else {
                    ValueNode* val_cur = new ValueNode(cur);
                    val_cur->next = head;
                    head->pre = val_cur;
                    head = val_cur;                     //更新head
                    valDict[1] = val_cur;
                }
            }
        }
    }

    void dec(string key) {
        if(keyDict.find(key) == keyDict.end())
            return;
        KeyNode* cur = keyDict[key];
        KeyNode* key_pre = cur->pre;
        KeyNode* key_nx = cur->next;
        if(key_pre != NULL)
            key_pre->next = key_nx;
        if(key_nx != NULL)
            key_nx->pre = key_pre;
        int val = cur->val;
        ValueNode* val_pre = valDict[val]->pre;
        ValueNode* val_nx = valDict[val];
        cur->val -= 1;
        if(valDict[val]->first == cur) {
            valDict[val]->first = key_nx;
            if(key_nx == NULL) {
                ValueNode* v = valDict[val];
                val_nx = v->next;
                if(val_nx != NULL)
                    val_nx->pre = val_pre;
                if(val_pre != NULL)
                    val_pre->next = val_nx;
                valDict.erase(val);
                delete(v);
            }
        }
        if(val_pre == NULL) {
            if(cur->val == 0) {
                //值减为0，删除该节点
                keyDict.erase(key);
                delete(cur);
                head = val_nx;          //更新head域
                if(val_nx == NULL)      //更新tail域
                    tail = val_pre;
            }
            else {
                ValueNode* val_cur = new ValueNode(cur);
                valDict[val_cur->val] = val_cur;
                val_cur->next = val_nx;
                if(val_nx != NULL)
                    val_nx->pre = val_cur;
                else
                    tail = val_cur;
                head = val_cur;
            }
        }
        else {
            if(cur->val == 0) {
                keyDict.erase(key);
                delete(cur);
                if(val_nx == NULL)      //更新tail域
                    tail = val_pre;
            }
            else {
                if(val_pre->val == cur->val) {
                    //插入到前一个valNode中
                    KeyNode* tmp = val_pre->first;
                    cur->next = tmp;
                    tmp->pre = cur;
                    val_pre->first = cur;
                    if(val_nx == NULL)      //更新tail域
                        tail = val_pre;
                }
                else {
                    //插入一个新的valNode
                    ValueNode* val_cur = new ValueNode(cur);
                    valDict[val_cur->val] = val_cur;
                    val_cur->next = val_nx;
                    if(val_nx != NULL)
                        val_nx->pre = val_cur;
                    else
                        tail = val_cur;
                    val_pre->next = val_cur;
                    val_cur->pre = val_pre;
                }
            }
        }
    }

    string getMaxKey() {
        if(tail == NULL)
            return "";
        int val = tail->val;
        string key = valDict[val]->first->key;
        return key;
    }

    string getMinKey() {
        if(head == NULL)
            return "";
        int val = head->val;
        string key = valDict[val]->first->key;
        return key;
    }

    void print() {
        ValueNode* p = head;
        while(p != NULL) {
            KeyNode* cur = p->first;
            cout << "Val: " << p->val << endl;
            cout << "Key: ";
            while(cur != NULL) {
                cout << cur->key << " ";
                cur = cur->next;
            }
            p = p->next;
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    AllOne obj;
    while(true) {
        cout << "0: Inc" << endl;
        cout << "1: Dec" << endl;
        cout << "2: Max" << endl;
        cout << "3: Min" << endl;
        cout << "4: Print" << endl;
        cout << endl;
        int k;
        cin >> k;
        if(k == 0) {
            string key;
            cin >> key;
            obj.inc(key);
        }
        else if(k == 1) {
            string key;
            cin >> key;
            obj.dec(key);
        }
        else if(k == 2) {
            cout << "MaxKey: " << obj.getMaxKey() << endl;
        }
        else if(k == 3) {
            cout << "MinKey: " << obj.getMinKey() << endl;
        }
        else {
            obj.print();
        }
        cout << endl;
    }
    return 0;
}

