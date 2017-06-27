#include <iostream>
#include <vector>

using namespace std;

/*
 * Integer Replacement
 *
 * Given a positive integer n and you can do operations as follow:
 *
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * What is the minimum number of replacements needed for n to become 1?
 *
 * Example 1:
 *
 * Input:
 * 8
 *
 * Output:
 * 3
 *
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 * Example 2:
 *
 * Input:
 * 7
 *
 * Output:
 * 4
 *
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 *
 *
 */

int integerReplacement(int m) {
    int cnt = 0;
    long n = m;
    while(n > 1) {
        while(n > 0 && (n & 1) == 0) {
            n >>= 1;
            cnt++;
        }
        if(n <= 1)
            break;
        int tmp1 = 0;
        long n1 = n + 1;
        while(n1 > 0 && (n1 & 1) == 0) {
            n1 >>= 1;
            tmp1++;
        }
        int tmp2 = 0;
        long n2 = n - 1;
        while(n2 > 0 && (n2 & 1) == 0) {
            n2 >>= 1;
            tmp2++;
        }
        if(n1 < n2) {
            n = n1;
            cnt += tmp1 + 1;
        } 
        else if(n1 > n2){
            n = n2;
            cnt += tmp2 + 1;
        }
        else {
        	if(tmp1 < tmp2) {
        		n = n1;
        		cnt += tmp1 + 1;
        	}
        	else {
        		n = n2;
        		cnt += tmp2 + 1;
        	}
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    int res = integerReplacement(n);
    cout << res << endl;
    return 0;
}
