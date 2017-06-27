#include <iostream>
#include <vector>
#include <limits>

/*
 * Super Ugly Number
 *
 * Write a program to find the nth super ugly number.
 *
 * Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
 *
 * Note:
 * (1) 1 is a super ugly number for any given primes.
 * (2) The given numbers in primes are in ascending order.
 * (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * (4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 *
 *
 */

using namespace std;

void print(vector<int>& nums) {
	for(auto iter = nums.begin(); iter != nums.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

long nthSuperUglyNumber(int n, vector<int>& primes) {
    if(n <= 0)
        return 0;
    vector<int> res;
    res.push_back(1);
    int k = primes.size();
    vector<int> cnt(k, 0);
    while(res.size() < n) {
        int val = 0;
        for(int i = 0; i < k; i++) {
            int tmp = res[cnt[i]] * primes[i];
            if(tmp > res.back() && (val <= 0 || tmp <= val))
                val = tmp;
        }
        for(int i = 0; i < k; i++) {
            int tmp = res[cnt[i]] * primes[i];
            if(tmp == val)
                cnt[i]++;
        }
        res.push_back(val);
    }
    print(res);
    return res.back();
}

int main() {
    int n;
    cin >> n;
    int val;
    vector<int> primes;
    while(cin >> val) {
        primes.push_back(val);
    }
    int res = nthSuperUglyNumber(n, primes);
    cout << res << endl;
    return 0;
}
