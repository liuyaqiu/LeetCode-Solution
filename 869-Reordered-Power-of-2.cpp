class Solution {
public:
    bool reorderedPowerOf2(int N) {
        long long power2 = 1;
        long long max_n = pow(10.0, ceil(log10(N)) + 1);
        string target;
        string N_str = to_string(N);
        vector<int> N_digits(10, 0);
        for (int i = 0; i < N_str.length(); i++) {
            N_digits[N_str[i] - '0'] += 1;
        }
        for (int i = 0; i < N_digits.size(); i++) {
            target += '0' + N_digits[i];
        }
        while (power2 < max_n) {
            string str = to_string(power2);
            vector<int> digits(10, 0);
            for (int i = 0; i < str.length(); i++) {
                digits[str[i] - '0'] += 1;
            }
            string count;
            for (int i = 0; i < digits.size(); i++) {
                count += '0' + digits[i];
            }
            if (count == target) {
                return true;
            }
            power2 *= 2;
        }
        return false;
    }
};