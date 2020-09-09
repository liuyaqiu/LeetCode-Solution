class Solution {
public:
    bool isBipartite(const vector<vector<int>>& graph) {
        queue<int> next_nodes;
        queue<int> cur_nodes;
        vector<int> colors(graph.size(), -1);
        int current_color = 0;
        cur_nodes.push(0);
        while (!cur_nodes.empty()) {
            int cur = cur_nodes.front();
            cur_nodes.pop();
            if (colors[cur] == -1) {
                colors[cur] = current_color;
            } else {
                if (colors[cur] != current_color) {
                    return false;
                }
            }
            for (int neighbor : graph[cur]) {
                if (colors[neighbor] == -1) {
                    next_nodes.push(neighbor);
                } else {
                    if (colors[neighbor] == colors[cur]) {
                        return false;
                    }
                }
            }
            if (cur_nodes.empty()) {
                if (!next_nodes.empty()) {
                    cur_nodes = next_nodes;
                    next_nodes = {};
                } else {
                    for (int i = 0; i < colors.size(); i++) {
                        if (colors[i] == -1) {
                            cur_nodes.push(i);
                            break;
                        }
                    }
                }
                current_color = !current_color;
            }
        }
        return true;
    }
};