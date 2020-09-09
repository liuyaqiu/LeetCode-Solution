class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0;
        int index = 0;
        while (index < int(A.size()) - 2) {
            int cur = index;
            while (cur + 1 < A.size() && A[cur] < A[cur + 1]) {
                cur++;
            }
            if (cur + 1 < A.size() && A[cur] == A[cur + 1]) {
                while (cur + 1 < A.size() && A[cur] == A[cur + 1]) {
                    cur++;
                }
                index = cur;
                continue;
            }
            int increasing = cur - index + 1;
            int prev = cur;
            while (cur + 1 < A.size() && A[cur] > A[cur + 1]) {
                cur++;
            }
            int decreasing = cur - prev + 1;
            if (increasing > 1 && decreasing > 1) {
                res = max(res, increasing + decreasing - 1);
            }
            index = cur;
        }
        return res;
    }
};