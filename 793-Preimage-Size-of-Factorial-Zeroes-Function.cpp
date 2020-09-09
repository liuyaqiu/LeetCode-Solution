class Solution {
public:
    int count(int m) {
        int res = 0;
        while (m > 0) {
            res += m;
            m = m / 5;
        }
        return res;
    }
    int preimageSizeFZF(int K) {
        int low = 0, high = K;
        while (low <= high) {
            int mid = (low + high) / 2;
            int cur = count(mid);
            if (cur == K) {
                return 5;
            } else if (cur < K) {
                low = mid + 1;
            } else if (cur > K) {
                high = mid - 1;
            }
        }
        return 0;
    }
};