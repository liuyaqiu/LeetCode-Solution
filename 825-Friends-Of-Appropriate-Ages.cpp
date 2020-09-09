class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        vector<int> age_count(120 + 1, 0);
        for (int i = 0; i < ages.size(); i++) {
            age_count[ages[i]] += 1;
        }
        for (int i = 1; i < age_count.size(); i++) {
            for (int j = 1; j < age_count.size(); j++) {
                if (age_count[i] == 0 || age_count[j] == 0 || j <= 0.5 * i + 7 || j > i || (j > 100 && i < 100)) {
                    continue;
                }
                if (i == j) {
                    res += age_count[i] * (age_count[i] - 1);
                } else {
                    res += age_count[i] * age_count[j];
                }
            }
        }
        return res;
    }
};