class Solution {
public:
    void DFS(const vector<vector<int>>& graph, int cur, vector<vector<int>>& res, vector<int>& path) {
        path.push_back(cur);
        if (cur == graph.size() - 1) {
            res.push_back(path);
        }
        for (int child : graph[cur]) {
            DFS(graph, child, res, path);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(graph, 0, res, path);
        return res;
    }
};