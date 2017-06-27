#include <iostream>
#include <vector>

using namespace std;

/*
 * Reverse String
 *
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh".
 *
 *
 */

string reverseString(string s) {
    int low = 0, high = s.length() - 1;
    while(low < high) {
    	char c = s[low];
    	s[low] = s[high];
    	s[high] = c;
    	low++;
    	high--;
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    string res = reverseString(s);
    cout << res << endl;
    return 0;
}
