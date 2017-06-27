#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
 * Add Digits
 *
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *
 * For example:
 *
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 *
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 *
 * Hint:
 *
 * A naive implementation of the above process is trivial. Could you come up with other methods?
 * What are all the possible results?
 * How do they occur, periodically or randomly?
 *
 *
 */

int add(int a, int b) {
    int c = a + b;
    return c / 10 + c % 10;
}

int addDigit(int num) {
    int res = 0;
    string str;
    stringstream ss;
    ss << num;
    ss >> str;
    for(int i = 0; i < str.length(); i++)
        res = add(res, str[i] - '0');
    return res;
}

int main() {
    int num;
    cin >> num;
    int res = addDigit(num);
    cout << res << endl;
    return 0;
}
