#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

/*
 * Reconstruct Itinerary
 *
 * Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
 *
 * Note:
 * If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * Example 1:
 * tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
 * Example 2:
 * tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
 * Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 *
 *
 */

struct mycomp {
    bool operator() (const string& lhs, const string& rhs) const {
        return lhs < rhs;
    }
};

map<string, set<string, mycomp>, mycomp> getMap(vector<pair<string, string>>& tickets) {
    map<string, set<string, mycomp>, mycomp> result;
    for(auto ticket: tickets) {
        string from = ticket.first;
        string to = ticket.second;
        if(result.find(from) != result.end())
            result[from].insert(to);
        else
            result[from] = {to};
    }
    return result;
}

void visit(map<string, set<string, mycomp>, mycomp>& graph, map<pair<string, string>, int>& edges, string cur, vector<string>& path, int n) {
    if(graph.find(cur) == graph.end())
        return;
    if(path.size() == n + 1)
        return;
    set<string, mycomp> neighbours = graph[cur];
    if(neighbours.empty()) {
        path.push_back(cur);
        if(path.size() == n + 1)
            return;
        else
            path.pop_back();
    }
    else {
        for(auto nb: neighbours) {
            pair<string, string> edge = pair<string, string>(cur, nb);
            if(edges.find(edge) == edges.end())
                return;
            else {
                if(edges[edge] == 0)
                    continue;
                else {
                    edges[edge] -= 1;
                    path.push_back(nb);
                    visit(graph, edges, nb, path, n);
                    if(path.size() == n + 1)
                        return;
                    path.pop_back();
                    edges[edge] += 1;
                }
            }
        }
    }
}

vector<string> getItinerary(map<string, set<string, mycomp>, mycomp>& graph, map<pair<string, string>, int>& edges, int n) {
    string cur = "JFK";
    vector<string> path = {cur};
    visit(graph, edges, cur, path, n);
    return path;
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    map<string, set<string, mycomp>, mycomp> graph = getMap(tickets);
    int n = tickets.size();
    map<pair<string, string>, int> edges;
    for(auto ticket: tickets) {
        if(edges.find(ticket) == edges.end())
            edges[ticket] = 1;
        else
            edges[ticket] += 1;
    }
    //printMap(graph);
    //printEdges(edges);
    vector<string> res = getItinerary(graph, edges, n);
    return res;
}

void printMap(map<string, set<string, mycomp>, mycomp>& graph) {
    for(auto node: graph) {
        string cur = node.first;
        set<string, mycomp> nbs = node.second;
        cout << "Node: " << cur << endl;
        cout << "Neighbours: ";
        for(auto nb: nbs)
            cout << nb << " ";
        cout << endl;
    }
    cout << endl;
}

void printEdges(map<pair<string, string>, int>& edges) {
    for(auto edge: edges) {
        pair<string, string> ticket = edge.first;
        int visit = edge.second;
        cout << ticket.first << " " << ticket.second << " " << visit << endl;
    }
}

int main() {
    string from, to;
    vector<pair<string, string>> tickets;
    while(cin >> from >> to)
        tickets.push_back(pair<string, string>(from, to));
    vector<string> res = findItinerary(tickets);
    for(auto s: res)
        cout << s << " ";
    cout << endl;
    return 0;
}

//EZE AXA TIA ANU ANU JFK JFK ANU ANU EZE TIA ANU AXA TIA TIA JFK ANU TIA JFK TIA
