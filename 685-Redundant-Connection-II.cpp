/*
  Redundant Connection II

  n this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    map<int, set<int>> child;
    map<int, set<int>> parent;
    for(auto edge: edges) {
        int u = edge[0], v = edge[1];
        if(child.find(u) != child.end())
            child[u].insert(v);
        else
            child[u] = {v};
        if(parent.find(v) != parent.end())
            parent[v].insert(u);
        else
            parent[v] = {u};
    }
    //删除叶子节点
    while(true) {
        bool judge = false;
        for(auto item: parent) {
            int point = item.first;
            if(child.find(point) == child.end() && parent[point].size() == 1) {
                judge = true;
                for(auto father: item.second) {
                    child[father].erase(point);
                    if(child[father].empty())
                        child.erase(father);
                }
                parent.erase(point);
            }
        }
        if(!judge)
            break;
    }
    //如果有汇点，输出汇点
    for(auto item: parent) {
        if(item.second.size() == 2 && child.find(item.first) == child.end()) {
            int point = item.first;
            for(auto iter = edges.rbegin(); iter != edges.rend(); iter++) {
                if((*iter)[1] == point)
                    return *iter;
            }
        }
    }
    //如果有根节点，输出根进入环的部分
    int root = -1;
    for(auto item: child) {
        int point = item.first;
        if(parent.find(point) == parent.end()) {
            root = point;
            break;
        }
    }
    if(root != -1) {
        int prev = root;
        root = *child[root].begin();
        while(parent[root].size() == 1) {
            prev = root;
            root = *child[root].begin();
        }
        for(auto item: parent[root]) {
            if(item != prev)
                return {item, root};
        }
    }
    //没有根节点，从环路中选取合适的边输出
    for(auto iter = edges.rbegin(); iter != edges.rend(); iter++) {
        int u = (*iter)[0], v = (*iter)[1];
        if(child.find(u) != child.end() && child.find(v) != child.end())
            return *iter;
    }
    return {};
}
