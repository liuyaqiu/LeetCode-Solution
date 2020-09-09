class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int even_sum = 0;
        for (int num : A) {
            if (num % 2 == 0) {
                even_sum += num;
            }
        }
        vector<int> res;
        for (const auto& query : queries) {
            int val = query[0];
            int index = query[1];
            if (A[index] % 2 == 0) {
                if (val % 2 == 0) {
                    even_sum += val;
                } else {
                    even_sum -= A[index]; // new value is odd, remove;
                }
                A[index] += val;
            } else {
                if (val % 2 != 0) {
                    even_sum += A[index] + val; // new value is even, add;
                }
                A[index] += val;
            }
            res.push_back(even_sum);
        }
        return res;
    }
};