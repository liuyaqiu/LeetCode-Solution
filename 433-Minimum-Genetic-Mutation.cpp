class Solution {
public:
    void dfs_search(int cur, int target, const vector<vector<int>>& neighbors, unordered_set<int>& visit, int& cur_dis, int& res) {
        if (visit.find(cur) != visit.end()) {
            return;
        }
        if (cur == target) {
            res = cur_dis;
            return;
        }
        visit.insert(cur);
        cur_dis += 1;
        for (int neighbor : neighbors[cur]) {
            dfs_search(neighbor, target, neighbors, visit, cur_dis, res);
        }
        visit.erase(cur);
        cur_dis -= 1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int start_index = -1;
        int end_index = -1;
        for (int i = 0; i < bank.size(); i++) {
            if (bank[i] == start) {
                start_index = i;
            }
            if (bank[i] == end) {
                end_index = i;
            }
        }
        if (start_index == -1) {
            bank.push_back(start);
            start_index = bank.size() - 1;
        }
        vector<vector<int>> neighbors(bank.size(), vector<int>{});
        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                int cnt = 0;
                for (int k = 0; k < bank[i].length(); k++) {
                    if (bank[i][k] != bank[j][k]) {
                        cnt += 1;
                    }
                }
                if (cnt == 1) {
                    neighbors[i].push_back(j);
                    neighbors[j].push_back(i);
                }
            }
        }
        int cur_dis = 0;
        int res = -1;
        unordered_set<int> visit;
        dfs_search(start_index, end_index, neighbors, visit, cur_dis, res);
        return res;
    }
};