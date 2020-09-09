/*
 * Count and Say
 *
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth term of the count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a string.
 *
 * Example 1:
 *
 * Input: 1
 * Output: "1"
 * Example 2:
 *
 * Input: 4
 * Output: "1211"
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string nextStr(string s) {
    int i = 0;
    int cnt = 1;
    string res;
    while(i < s.length() - 1) {
        if(s[i] == s[i + 1]) {
            cnt += 1;
        }
        else {
            res.push_back('0' + cnt);
            res.push_back(s[i]);
            cnt = 1;
        }
        i += 1;
    }
    res.push_back('0' + cnt);
    res.push_back(s[s.length() - 1]);
    return res;
}

int main() {
    int n;
    cin >> n;
    string s = "1";
    cout << s << endl;
    while(n > 0) {
        s = nextStr(s);
        cout << s << endl;
        n -= 1;
    }
    return 0;
}
