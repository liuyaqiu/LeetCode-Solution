class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> front_and_back;
        for (int i = 0; i < fronts.size(); i++) {
            if (fronts[i] == backs[i]) {
                front_and_back.insert(fronts[i]);
            }
        }
        int res = 0;
        for (int i = 0; i < fronts.size(); i++) {
            if (!front_and_back.count(fronts[i])) {
                if (res == 0 || fronts[i] < res) {
                    res = fronts[i];
                }
            }
            if (!front_and_back.count(backs[i])) {
                if (res == 0 || backs[i] < res) {
                    res = backs[i];
                }
            }
        }
        return res;
    }
};