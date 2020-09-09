class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        auto compare = [](const pair<int, int>& lhs, const pair<int ,int>& rhs) {
            return lhs.first < rhs.first;
        };
        vector<pair<int, int>> values_and_index;
        for (int i = 0; i < B.size(); i++) {
            values_and_index.push_back({B[i], i});
        }
        sort(values_and_index.begin(), values_and_index.end(), compare);
        vector<int> res(A.size(), -1);
        sort(A.begin(), A.end());
        unordered_set<int> used_index;
        int index = -1;
        for (int i = 0; i < values_and_index.size(); i++) {
            auto iter = upper_bound(A.begin() + index + 1, A.end(), values_and_index[i].first);
            if (iter == A.end()) {
                break;
            }
            res[values_and_index[i].second] = *iter;
            index = distance(A.begin(), iter);
            used_index.insert(index);
        }
        vector<int> unused_index;
        for (int i = 0; i < A.size(); i++) {
            if (!used_index.count(i)) {
                unused_index.push_back(i);
            }
        }
        int k = 0;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != -1) {
                continue;
            }
            res[i] = A[unused_index[k++]];
        }
        return res;
    }
};