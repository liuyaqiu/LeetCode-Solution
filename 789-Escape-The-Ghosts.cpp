class Solution {
public:
    bool canCatch(const vector<int>& ghost, const vector<int>& target) {
        return (abs(ghost[0] - target[0]) + abs(ghost[1] - target[1])) <= (abs(target[0]) + abs(target[1]));
    }

    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        for (const auto& ghost : ghosts) {
            if (canCatch(ghost, target)) {
                return false;
            }
        }
        return true;
    }
};