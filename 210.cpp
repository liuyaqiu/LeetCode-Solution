#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void print(vector<vector<int>>& adj) {
    for(auto iter1 = adj.begin(); iter1 != adj.end(); iter1++) {
        for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++)
            cout << *iter2 << " ";
        cout << endl;
    }
    cout << endl;
}

void printArray(vector<bool>& temp) {
    for(auto iter = temp.begin(); iter != temp.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}


void visit(bool& res, int node, vector<int>& path, vector<vector<int>>& adj, vector<bool>& temp, vector<bool>& perm) {
    if(!res)
        return;
    if(temp[node]) {
        res = false;
        return;
    }
    else {
        if(!perm[node]) {
            path.push_back(node);
            temp[node] = true;
            for(auto iter = adj[node].begin(); iter != adj[node].end(); iter++)
                visit(res, *iter, path, adj, temp, perm);
            perm[node] = true;
            temp[node] = false;
        }
    }
}

vector<vector<int>> getAdj(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> res(numCourses, vector<int>());
    for(auto iter = prerequisites.begin(); iter != prerequisites.end(); iter++) {
        res[iter->second].push_back(iter->first);
    }
    return res;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj = getAdj(numCourses, prerequisites);
    vector<bool> temp(numCourses, false);
    vector<bool> perm(numCourses, false);
    vector<int> path;
    vector<int> order;
    bool res = true;
    while(res) {
        int node = 0;
        while(node < perm.size() && perm[node]) {
            node++;
        }
        if(node >= perm.size())
            break;
        else
            visit(res, node, path, adj, temp, perm);
        if(res) {
            for(auto iter = path.rbegin(); iter != path.rend(); iter++)
                order.push_back(*iter);
            path.clear();
        }
    }
    if(!res)
        order.clear();
    return order;
}

int main() {
    int num;
    cin >> num;
    vector<pair<int, int>> pre;
    int x, y;
    while(cin >> x >> y) {
        pre.push_back(pair<int, int>(x, y));
    }
    vector<int> res = findOrder(num, pre);
    for(auto iter = res.begin(); iter != res.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    cout << endl;
    return 0;
}

