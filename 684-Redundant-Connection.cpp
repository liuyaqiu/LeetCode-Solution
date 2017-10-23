/*
  Redundant Connection

  In this problem, a tree is an undirected graph that is connected and has no cycles.

  The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

  The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

  Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    map<int, set<int>> graph;
    for(auto edge: edges) {
        int u = edge[0], v = edge[1];
        if(graph.find(u) != graph.end())
            graph[u].insert(v);
        else
            graph[u] = {v};
        if(graph.find(v) != graph.end())
            graph[v].insert(u);
        else
            graph[v] = {u};
    }
    while(true) {
        bool judge = true;
        for(auto node: graph) {
            if(node.second.size() == 1) {
                int v = *(node.second.begin());
                graph[v].erase(node.first);
                graph.erase(node.first);
                judge = false;
            }
        }
        if(judge)
            break;
    }
    for(int i = edges.size() - 1; i >= 0; i--) {
        int u = edges[i][0], v = edges[i][1];
        if(graph.find(u) != graph.end() && graph.find(v) != graph.end())
            return edges[i];
    }
    return {};
}
