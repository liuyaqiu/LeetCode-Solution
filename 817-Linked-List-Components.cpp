/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

const int maxn = 20000 + 5;
int bin[maxn];
int sz[maxn];

void init(int size) {
    for (int i = 0; i < size; i++) {
        bin[i] = i;
        sz[i] = 1;
    }
}

int findX(int x) {
    int r = x;
    while (bin[r] != r) {
        r = bin[r];
    }
    return r;
}

void merge(int a, int b) {
    int aRoot = findX(a);
    int bRoot = findX(b);
    if (aRoot == bRoot) {
        return;
    }
    if (sz[aRoot] < sz[bRoot]) {
        bin[aRoot] = bRoot;
        sz[bRoot] += sz[aRoot];
    } else {
        bin[bRoot] = aRoot;
        sz[aRoot] += sz[bRoot];
    }
}

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        init(10000);
        unordered_set<int> nodes;
        for (int node : G) {
            nodes.insert(node);
        }
        while (head != nullptr) {
            int cur_val = head->val;
            if (head->next == nullptr) {
                break;
            }
            int next_val = head->next->val;
            if (nodes.find(next_val) != nodes.end() && nodes.find(cur_val) != nodes.end()) {
                merge(cur_val, next_val);
            }
            head = head->next;
        }
        unordered_set<int> roots;
        for (int node : G) {
            roots.insert(findX(node));
        }
        return roots.size();
    }
};