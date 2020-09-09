class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> first_count(26, 0);
        for (int j = 0; j < A[0].length(); j++) {
            first_count[A[0][j] - 'a'] += 1;
        }
        for (int i = 1; i < A.size(); i++) {
            vector<int> cnt(26, 0);
            for (int j = 0; j < A[i].length(); j++) {
                cnt[A[i][j] - 'a'] += 1;
            }
            for (int k = 0; k < cnt.size(); k++) {
                first_count[k] = min(first_count[k], cnt[k]);
            }
        }
        vector<string> res;
        for (int i = 0; i < first_count.size(); i++) {
            for (int j = 0; j < first_count[i]; j++) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};