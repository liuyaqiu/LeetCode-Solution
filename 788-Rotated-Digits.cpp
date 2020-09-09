class Solution {
public:
    int countAll(int N) {
        if (N < 0) {
            return 0;
        }
        vector<int> nums = {1, 2, 3, 3, 3, 4, 5, 5, 6, 7};
        if (N < 10) {
            return nums[N];
        }
        int k = ceil(log10(N));
        if (pow(10.0, k) == N) {
            k += 1;
        }
        int max_d = N / int(pow(10.0, k - 1));
        int cur = pow(7.0, k - 1);
        int res = 0;
        if (max_d >= 1) {
            res += cur;
        }
        if (max_d >= 2) {
            res += cur;
        }
        if (max_d >= 3) {
            res += cur;
        }
        if (max_d >= 6) {
            res += cur;
        }
        if (max_d >= 7) {
            res += cur;
        }
        if (max_d >= 9) {
            res += cur;
        }
        int remain = N % int(pow(10.0, k - 1));
        if (max_d == 1 || max_d == 2 || max_d == 5 || max_d == 6 || max_d == 8 || max_d == 9) {
            res += countAll(remain);
        }
        return res;
    }

    int countNot(int N) {
        if (N < 0) {
            return 0;
        }
        vector<int> nums = {1, 2, 2, 2, 2, 2, 2, 2, 3, 3};
        if (N < 10) {
            return nums[N];
        }
        int k = ceil(log10(N));
        if (pow(10.0, k) == N) {
            k += 1;
        }
        int max_d = N / int(pow(10.0, k - 1));
        int cur = pow(3.0, k - 1);
        int res = 0;
        if (max_d >= 1) {
            res += cur;
        }
        if (max_d >= 2) {
            res += cur;
        }
        if (max_d >= 9) {
            res += cur;
        }
        int remain = N % int(pow(10.0, k - 1));
        if (max_d == 1 || max_d == 8) {
            res += countNot(remain);
        }
        return res;
    }
    int rotatedDigits(int N) {
        int k = ceil(log10(N));
        if (pow(10.0, k) == N) {
            k += 1;
        }
        int r1 = countAll(N);
        int r2 = countNot(N);
        return r1 - r2;
    }
};