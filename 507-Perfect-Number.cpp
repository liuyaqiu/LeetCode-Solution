#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool checkPerfectNumber(int num) {
    if(num <= 3)
        return false;
    int m = sqrt(num);
    vector<bool> isprime(m + 1, true);
    int p = 2;
    while(p <= m) {
        for(int i = 2 * p; i <= m; i += p)
            isprime[i] = false;
        p += 1;
        while(!isprime[p])
            p++;
    }
    vector<int> prime;
    for(int i = 2; i <= m; i++) {
        if(isprime[i])
            prime.push_back(i);
    }
    vector<int> factor;
    vector<int> times;
    int n = num;
    for(int i = 0; i < (int)prime.size() && n > 1; i++) {
        if(n % prime[i] == 0) {
            factor.push_back(prime[i]);
            times.push_back(0);
        }
        while(n % prime[i] == 0) {
            times.back() += 1;
            n /= prime[i];
        }
    }
    if(n > 1) {
        factor.push_back(n);
        times.push_back(1);
    }
    long sum = 1;
    for(int i = 0; i < (int)factor.size(); i++) {
        long tmp = (long)(pow(factor[i], times[i] + 1) - 1) / (factor[i] - 1);
        if(sum * tmp > 2 * num)
            return false;
        else
            sum *= tmp;
    }
    return sum == 2 * num;
}

int main() {
    int n;
    cin >> n;
    bool res = checkPerfectNumber(n);
    cout << res << endl;
    return 0;
}
