#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Additive Number
 *
 * Additive number is a string whose digits can form additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
 *
 * For example:
 * "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 *
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *
 * Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
 *
 * Follow up:
 * How would you handle overflow for very large input integers?
 *
 *
 */

string add(string num1, string num2) {
    if(num2.length() > num1.length())
        swap(num1, num2);
    string res = num1;
    int n2 = num2.length(), n1 = num1.length();
    int pos = 0;
    int pre = 0;
    while(pos < n2) {
        int a = num2[n2 - 1 - pos] - '0';
        int b = res[n1 - 1 - pos] - '0';
        b += a + pre;
        int c = b % 10;
        pre = b / 10;
        res[n1 - 1 - pos] = c + '0';
        pos++;
    }
    while(pos < n1 && pre > 0) {
        int b = res[n1 - 1 - pos] - '0';
        b += pre;
        int c = b % 10;
        pre = b / 10;
        res[n1 - 1 - pos] = c + '0';
        pos++;
    }
    if(pre > 0)
        res = "1" + res;
    return res;
}

bool isValid(string num) {
    return num.length() == 1 || num[0] != '0';
}

bool search(string a, string b, string c) {
    string d = add(a, b);
    int n = c.length();
    int m = d.length();
    if(!isValid(d) || m > n || c.substr(0, m) != d)
        return false;
    if (c == d)
        return true;
    else
        return search(b, d, c.substr(m, n - m));
}

bool isAdditiveNumber(string num) {
    int n = num.length();
    for(int i = 1; i < n / 2 + 1; i++) {
        for(int j = i + 1; j < n; j++) {
            string a = num.substr(0, i);
            string b = num.substr(i, j - i);
            if(isValid(a) && isValid(b)) {
	            string c = num.substr(j, n - j);
	            if(search(a, b, c))
	                return true;
            }
        }
    }
    return false;
}

int main() {
    string str;
    cin >> str;
    bool res = isAdditiveNumber(str);
    cout << res << endl;
    return 0;
}
