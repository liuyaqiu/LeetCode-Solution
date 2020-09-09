class Solution {
public:
    void DFS(const vector<unordered_set<int>>& richer_people, const vector<int>& quiet, vector<bool>& visited, int index, int& res) {
        if (index < 0 || index >= visited.size() || visited[index]) {
            return;
        }
        if (res == -1 || quiet[index] < quiet[res]) {
            res = index;
        }
        visited[index] = true;
        for (int next : richer_people[index]) {
            DFS(richer_people, quiet, visited, next, res);
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<unordered_set<int>> richer_people(quiet.size());
        for (const auto& x_and_y : richer) {
            richer_people[x_and_y[1]].insert(x_and_y[0]);
        }
        unordered_map<int, int> cache;
        vector<int> res(quiet.size(), -1);
        for (int i = 0; i < quiet.size(); i++) {
            vector<bool> visited(quiet.size(), false);
            DFS(richer_people, quiet, visited, i, res[i]);
        }
        return res;
    }
};