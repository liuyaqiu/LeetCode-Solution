#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct KeyNode {
    int key;
    int val;
    int freq;
    KeyNode* pre;
    KeyNode* next;
    KeyNode(int k, int v): key(k), val(v), freq(1), pre(NULL), next(NULL) {}
};

struct FreqNode {
    int freq;
    KeyNode* first;
    KeyNode* last;
    FreqNode* pre;
    FreqNode* next;
    FreqNode(KeyNode* k): freq(k->freq), first(k), last(k), pre(NULL), next(NULL) {}
};

class LFUCache {
private:
    unordered_map<int, KeyNode*> keyDict;
    unordered_map<int, FreqNode*> freqDict;
    FreqNode* head;
    int n;

    void evict() {
        if(keyDict.size() < n)
            return;
        FreqNode* freq_cur = head;
        KeyNode* key_cur = freq_cur->last;
        KeyNode* key_pre = key_cur->pre;
        keyDict.erase(key_cur->key);
        delete(key_cur);
        freq_cur->last = key_pre;
        if(key_pre != NULL)
            key_pre->next = NULL;
        else {
            head = freq_cur->next;
            freqDict.erase(key_cur->freq);
            delete(freq_cur);
        }
    }

    void insert(int key, int value) {
        if(n == 0)
            return;
        if(keyDict.find(key) != keyDict.end())
            return;
        evict();
        KeyNode* key_cur = new KeyNode(key, value);
        keyDict[key] = key_cur;
        if(freqDict.find(key_cur->freq) == freqDict.end()) {
            FreqNode* freq_cur = new FreqNode(key_cur);
            freqDict[key_cur->freq] = freq_cur;
            freq_cur->next = head;
            if(head != NULL)
                head->pre = freq_cur;
            head = freq_cur;
        }
        else {
            FreqNode* freq_cur = freqDict[key_cur->freq];
            KeyNode* start = freq_cur->first;
            start->pre = key_cur;
            key_cur->next = start;
            freq_cur->first = key_cur;
        }
    }

    void visit(int key) {
        KeyNode* key_cur = keyDict[key];
        int freq = key_cur->freq;
        FreqNode* freq_cur = freqDict[freq];
        KeyNode* key_nx = key_cur->next;
        KeyNode* key_pre = key_cur->pre;
        if(key_pre != NULL)
            key_pre->next = key_nx;
        if(key_nx != NULL)
            key_nx->pre = key_pre;
        FreqNode* freq_pre = freq_cur;
        FreqNode* freq_nx = freq_cur->next;
        if(freq_cur->first == key_cur) {
            freq_cur->first = key_nx;
            FreqNode* prev = freq_cur->pre;
            if(key_nx == NULL) {
                if(prev != NULL)
                    prev->next = freq_nx;
                if(freq_nx != NULL)
                    freq_nx->pre = prev;
                freqDict.erase(freq);
                delete(freq_cur);
                freq_pre = prev;
            }
        }
        else {
            if(freq_cur->last == key_cur)
                freq_cur->last = key_cur->pre;
        }
        //更新key_cur的状态
        key_cur->pre = NULL;
        key_cur->next = NULL;
        key_cur->freq += 1;
        if(freq_nx == NULL || freq_nx->freq != key_cur->freq) {
            FreqNode* tmp = new FreqNode(key_cur);
            freqDict[tmp->freq] = tmp;
            tmp->pre = freq_pre;
            tmp->next = freq_nx;
            if(freq_pre != NULL)
                freq_pre->next = tmp;
            else
                head = tmp;
            if(freq_nx != NULL)
                freq_nx->pre = tmp;
        }
        else {
            KeyNode* start = freq_nx->first;
            start->pre = key_cur;
            key_cur->next = start;
            freq_nx->first = key_cur;
            if(freq_pre == NULL)
                head = freq_nx;
        }
    }

public:
    LFUCache(int capacity): head(NULL), n(capacity) {}

    int get(int key) {
        if(keyDict.find(key) == keyDict.end())
            return -1;
        else {
            visit(key);
            return keyDict[key]->val;
        }
    }

    void put(int key, int value) {
        if(keyDict.find(key) == keyDict.end())
            insert(key, value);
        else {
            keyDict[key]->val = value;
            visit(key);
        }
    }

    void print() {
        cout << "********************" << endl;
        for(auto item: freqDict) {
            FreqNode* p = item.second;
            cout << "Freq: " << p->freq << endl;
            KeyNode* q = p->first;
            cout << "Key, Val: " << endl;
            while(q != NULL) {
                cout << q->key << "->" << q->val << endl;
                q = q->next;
            }
            p = p->next;
            cout << "--------------------" << endl;
            cout << endl;
        }
    }

};

int main() {
    int n;
    cout << "Input the cache capacity: ";
    cin >> n;
    LFUCache obj(n);
    while(true) {
        cout << "0: put" << endl;
        cout << "1: get" << endl;
        cout << "2: print" << endl;
        cout << endl;
        int k;
        cin >> k;
        if(k == 0) {
            int key, value;
            cin >> key >> value;
            obj.put(key, value);
        }
        else if(k == 1) {
            int key;
            cin >> key;
            cout << obj.get(key) << endl;
        }
        else {
            obj.print();
        }
    }
    return 0;
}

