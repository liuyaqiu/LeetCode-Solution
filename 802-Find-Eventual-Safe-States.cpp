class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<unordered_set<int>> output_nodes(graph.size(), unordered_set<int>());
        vector<unordered_set<int>> input_nodes(graph.size(), unordered_set<int>());
        for (int i = 0; i < graph.size(); i++) {
            for (int j : graph[i]) {
                output_nodes[i].insert(j);
                input_nodes[j].insert(i);
            }
        }
        unordered_map<int, int> output_degree;
        for (int i = 0; i < graph.size(); i++) {
            output_degree[i] = output_nodes[i].size();
        }
        vector<int> current_nodes;
        for (const auto& node_degree : output_degree) {
            if (node_degree.second == 0) {
                current_nodes.push_back(node_degree.first);
            }
        }
        for (int node : current_nodes) {
            output_degree.erase(node);
        }
        while (!current_nodes.empty()) {
            vector<int> next_nodes;
            for (int node : current_nodes) {
                for (int input : input_nodes[node]) {
                    output_degree[input] -= 1;
                    if (output_degree[input] == 0) {
                        next_nodes.push_back(input);
                    }
                }
            }
            current_nodes = next_nodes;
            for (int node : current_nodes) {
                output_degree.erase(node);
            }
        }
        vector<int> res;
        for (int i = 0; i < graph.size(); i++) {
            if (output_degree.find(i) == output_degree.end()) {
                res.push_back(i);
            }
        }
        return res;
    }
};