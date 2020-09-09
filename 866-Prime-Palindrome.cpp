class Solution {
public:
    vector<int> getPrimes(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = false;
        is_prime[1] = false;
        for (int k = 2; k < is_prime.size(); k++) {
            if (is_prime[k]) {
                for (int t = 2 * k; t < is_prime.size(); t += k) {
                    is_prime[t] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 0; i < is_prime.size(); i++) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
    
    bool checkPrime(const vector<int>& primes, int n) {
        auto iter = lower_bound(primes.begin(), primes.end(), n);
        if (iter != primes.end()) {
            return n == *iter;
        }
        for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
            if (n % primes[i] == 0) {
                return false;
            }
        }
        return true;
    }
    
    int generate_prime_palindrome(const vector<int>& primes, int max_n, int N) {
        int len = ceil(log10(max_n));
        for (int i = 2; i < 10; i++) {
            if (i >= N && checkPrime(primes, i)) {
                return i;
            }
        }
        for (int i = 1; i < int(pow(10.0, len / 2)); i++) {
            string left_part = to_string(i);
            string the_left = left_part;
            string the_right;
            reverse(left_part.begin(), left_part.end());
            the_right = left_part;
            string cur = the_left + the_right;
            long long num = stoll(cur);
            if (num >= N && checkPrime(primes, num)) {
                return num;
            }
            for (int c = 0; c < 10; c++) {
                cur = the_left + char('0' + c) + the_right;
                num = stoll(cur);
                if (num >= N && checkPrime(primes, num)) {
                    return num;
                }
            }
        }
        return -1;
    }

    int primePalindrome(int N) {
        int max_n = 2 * 100000000;
        vector<int> primes = getPrimes(int(ceil(sqrt(max_n))));
        return generate_prime_palindrome(primes, max_n, N);
    }
};