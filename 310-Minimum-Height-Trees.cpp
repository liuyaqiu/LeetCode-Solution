#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;

/*
 * Minimum Height Trees
 *
 * For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 *
 * Example 1:
 *
 * Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 *
 *         0
 *         |
 *         1
 *        / \
 *       2   3
 * return [1]
 *
 * Example 2:
 *
 * Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 *
 * 0  1  2
 *  \ | /
 *    3
 *    |
 *    4
 *    |
 *    5
 * return [3, 4]
 *
 *
 */

void print(vector<int>& res) {
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<int> res;
    if(n == 0)
        return res;
    if(n == 1) {
        res.push_back(0);
        return res;
    }
    vector<set<int>> nodes(n, set<int>());
    for(auto iter = edges.begin(); iter != edges.end(); iter++) {
        int v1 = iter->first;
        int v2 = iter->second;
        nodes[v1].insert(v2);
        nodes[v2].insert(v1);
    }
    vector<int> leaves;
    for(int i = 0; i < nodes.size(); i++) {
        if(nodes[i].size() == 1)
            leaves.push_back(i);
    }
    while(n > 2) {
        n = n - leaves.size();
        vector<int> tmp;
        for(auto iter = leaves.begin(); iter != leaves.end(); iter++) {
            int v1 = *iter;
            int v2 = *(nodes[v1].begin());
            nodes[v2].erase(v1);
            if(nodes[v2].size() == 1)
                tmp.push_back(v2);
        }
        leaves = tmp;
    }
    res = leaves;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    int v1, v2;
    for(int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2;
        edges.push_back(pair<int, int>(v1, v2));
    }
    vector<int> res = findMinHeighTrees(n, edges);
    print(res);
    return 0;
}
