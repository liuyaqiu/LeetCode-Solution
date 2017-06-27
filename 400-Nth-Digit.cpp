#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

/*
 * Nth Digit
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
 *
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n < 231).
 *
 * Example 1:
 *
 * Input:
 * 3
 *
 * Output:
 * 3
 * Example 2:
 *
 * Input:
 * 11
 *
 * Output:
 * 0
 *
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 *
 *
 */

void getParam(long n, long& dis, long& base, long& digits) {
    long cnt = 1;
    long len = 9 * pow(10, cnt - 1) * cnt;
    while(n > len) {
        n -= len;
        cnt++;
        len = 9 * pow(10, cnt - 1) * cnt;
    }
    long digit = ceil(n * 1.0 / (cnt * pow(10, cnt - 1)));
    base = digit * pow(10, cnt - 1);
    digits = cnt;
    dis = n - (digit - 1) * pow(10, cnt - 1) * cnt;
}

int findNthDigit(int n) {
    if(n < 10)
        return n;
    long base = 0;       //计数起始点
    long digits = 1;     //数的位数
    long dis = 0;    //计数位移
    getParam(n, dis, base, digits);
    long num = base + (ceil(dis * 1.0 / digits) - 1);
    string str;
    stringstream ss;
    ss << num;
    ss >> str;
    return str[(dis - 1) % digits] - '0';
}

int main() {
    int n;
    cin >> n;
    int res = findNthDigit(n);
    cout << res << endl;
    return 0;
}
