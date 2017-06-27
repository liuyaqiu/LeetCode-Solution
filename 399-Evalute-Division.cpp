#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*
 * Evaluate Division
 *
 * Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
 *
 * Example:
 * Given a / b = 2.0, b / c = 3.0. 
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
 * return [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 * The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
 *
 * According to the example above:
 *
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 * The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
 *
 *
 */

void findPath(vector<vector<int>>& nodes, vector<int>& visit, bool& has, int node, int target, vector<int>& path) {
    if(has || visit[node])
        return;
    visit[node] = true;
    path.push_back(node);
    if(node == target) {
        has = true;
        return;
    }
    vector<int> neighbors = nodes[node];
    for(auto nb: neighbors) {
        findPath(nodes, visit, has, nb, target, path);
    }
    if(!has)
        path.pop_back();
    visit[node] = false;
}

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    map<string, int> refer;
    int n = equations.size();
    vector<double> res;
    if(equations.empty() || queries.empty())
        return res;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        string start = equations[i].first;
        string end = equations[i].second;
        if(refer.find(start) == refer.end())
            refer[start] = cnt++;
        if(refer.find(end) == refer.end())
            refer[end] = cnt++;
    }
    vector<vector<int>> nodes(cnt, vector<int>());
    map<pair<int, int>, double> edges;
    for(int i = 0; i < n; i++) {
        string start = equations[i].first;
        string end = equations[i].second;
        int s = refer[start];
        int e = refer[end];
        nodes[s].push_back(e);
        edges[pair<int, int>(s, e)] = values[i];
        if(values[i] != 0.0) {
            nodes[e].push_back(s);
            edges[pair<int, int>(e, s)] = 1.0 / values[i];
        }
    }
    for(auto query: queries) {
        if(refer.find(query.first) == refer.end() || refer.find(query.second) == refer.end()) {
            res.push_back(-1.0);
            continue;
        }
        int s = refer[query.first];
        int e = refer[query.second];
        bool has = false;
        vector<int> visit(refer.size(), false);
        vector<int> path;
        findPath(nodes, visit, has, s, e, path);
        if(has) {
            double tmp = 1.0;
            cout << endl;
            for(int i = 0; i < path.size() - 1; i++) {
                double val = edges[pair<int, int>(path[i], path[i + 1])];
                tmp *= val;
            }
            res.push_back(tmp);
        }
        else
            res.push_back(-1.0);
    }
    return res;
}

