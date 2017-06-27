#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x): label(x) {}
};

struct cmp {
    bool operator() (const UndirectedGraphNode* p, const UndirectedGraphNode* q) {
        return p->label < q->label;
    }
};

void dfsNodeUtil(UndirectedGraphNode* node, set<UndirectedGraphNode*, cmp>& visit, stack<UndirectedGraphNode*>& remain, map<UndirectedGraphNode*, UndirectedGraphNode*, cmp>& refer) {
    refer[node] = new UndirectedGraphNode(node->label);
    visit.insert(node);
    for(auto iter = node->neighbors.begin(); iter != node->neighbors.end(); iter++) {
        if(visit.find(*iter) == visit.end()) {
            remain.push(*iter);
        }
    }
    if(remain.empty())
        return;
    UndirectedGraphNode* next = remain.top();
    remain.pop();
    dfsNodeUtil(next, visit, remain, refer);
}

void dfsNode(UndirectedGraphNode* node, map<UndirectedGraphNode*, UndirectedGraphNode*, cmp>& refer) {
    set<UndirectedGraphNode*, cmp> visit;
    stack<UndirectedGraphNode*> remain;
    dfsNodeUtil(node, visit, remain, refer);
}

void dfsLinkUtil(UndirectedGraphNode* node, set<UndirectedGraphNode*, cmp>& visit, stack<UndirectedGraphNode*>& remain, map<UndirectedGraphNode*, UndirectedGraphNode*, cmp>& refer) {
    UndirectedGraphNode* cur = refer[node];
    visit.insert(node);
    vector<UndirectedGraphNode*> tmp;
    for(auto iter = node->neighbors.begin(); iter != node->neighbors.end(); iter++) {
        tmp.push_back(refer[*iter]);
        if(visit.find(*iter) == visit.end()) {
            remain.push(*iter);
        }
    }
    cur->neighbors = tmp;
    if(remain.empty())
        return;
    UndirectedGraphNode* next = remain.top();
    remain.pop();
    dfsLinkUtil(next, visit, remain, refer);
}

void dfsLink(UndirectedGraphNode* node, map<UndirectedGraphNode*, UndirectedGraphNode*, cmp>& refer) {
    set<UndirectedGraphNode*, cmp> visit;
    stack<UndirectedGraphNode*> remain;
    dfsLinkUtil(node, visit, remain, refer);
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode* node) {
    if(node == NULL)
        return NULL;
    map<UndirectedGraphNode*, UndirectedGraphNode*, cmp> refer;
    dfsNode(node, refer);
    dfsLink(node, refer);
    return refer[node];
}

void dfsUtil(UndirectedGraphNode* node, set<UndirectedGraphNode*, cmp>& visit, stack<UndirectedGraphNode*>& remain) {
    cout << "Node: " << node->label << endl;
    visit.insert(node);
    cout << "Neighbors: ";
    for(auto iter = node->neighbors.begin(); iter != node->neighbors.end(); iter++) {
        cout << (*iter)->label << " ";
        if(visit.find(*iter) == visit.end())
            remain.push(*iter);
    }
    cout << endl;
    cout << endl;
    if(remain.empty())
        return;
    UndirectedGraphNode* next = remain.top();
    remain.pop();
    dfsUtil(next, visit, remain);
}

void dfs(UndirectedGraphNode* node) {
    set<UndirectedGraphNode*, cmp> visit;
    stack<UndirectedGraphNode*> remain;
    dfsUtil(node, visit, remain);
}

int main() {
	UndirectedGraphNode* node = new UndirectedGraphNode(0);
    vector<UndirectedGraphNode*> nb(2, node);
    node->neighbors = nb;
    dfs(node);
    UndirectedGraphNode* res = cloneGraph(node);
    dfs(res);
    return 0;
}
