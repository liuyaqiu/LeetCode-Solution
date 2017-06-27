#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverseWords(string s) {
    int p = 0;
    int n = s.length();
    while(p < n) {
        int start = p;
        int pos = s.find(' ', p);
        int end = n - 1;
        if(pos != -1)
            end = pos - 1;
        while(start < end)
            swap(s[start++], s[end--]);
        if(pos != -1)
        	p = pos + 1;
        else
        	break;
    }
    return s;
}

int main() {
    string s = "Let's take LeetCode contest";
    string res = reverseWords(s);
    cout << s << endl;
    cout << res << endl;
    return 0;
}
