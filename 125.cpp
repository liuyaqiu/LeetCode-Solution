#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool same(char a, char b) {
    if(a - '0' >= 0 && a - '0' <= 9)
        return b == a;
    else {
        if(b - '0' >= 0 && b - '0' <= 9)
            return false;
        else {
            int diff = a - b;
            return abs(diff) == 0 || abs(diff) == 32;
        }
    }
}

bool valid(char a) {
	return (a - '0' >= 0 && a - '0' <= 9) || (a - 'a' >= 0 && a - 'a' < 26) || (a - 'A' >= 0 && a - 'A' < 26);
}

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    while(left <= right) {
        while(left < s.length() && !valid(s[left]))
            left++;
        while(right >= 0 && !valid(s[right]))
            right--;
        if(left > right)
            break;
        if(same(s[left], s[right])) {
            left++;
            right--;
        }
        else
            return false;
    }
    return true;
}

int main() {
    string s = "A man0, a plan, a canal: Pa0 nama";
    if(isPalindrome(s))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
