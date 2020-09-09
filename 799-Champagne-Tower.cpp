class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured <= 0.0 || query_row < 0 || query_glass < 0 || query_glass > query_row) {
            return 0.0;
        }
        vector<double> prev_pour = {double(poured)};
        for (int i = 1; i <= query_row; i++) {
            vector<double> cur_pour(query_row + 1, 0);
            for (int j = 0; j < cur_pour.size(); j++) {
                if (j < prev_pour.size()) {
                    cur_pour[j] += max(0.0, prev_pour[j] - 1.0) * 0.5;
                }
                if (j - 1 >= 0 && j - 1 < prev_pour.size()) {
                    cur_pour[j] += max(0.0, prev_pour[j - 1] - 1.0) * 0.5;
                }
            }
            prev_pour = cur_pour;
        }
        return min(1.0, prev_pour[query_glass]);
    }
};