#include <iostream>
#include <vector>

using namespace std;

void reverseWords(string& s) {
	if(s.empty())
		return;
    string res = "";
    int start = 0;
    int end = 0;
    while(start < s.length() && s[start] == ' ')
    	start++;
    while(start < s.length()) {
        end = start + 1;
        while(end < s.length() && s[end] != ' ') {
            end++;
        }
        res = " " + s.substr(start, end - start) + res;
        start = end + 1;
        while(start < s.length() && s[start] == ' ') {
            start++;
        }
    }
    if(res.empty())
    	s = "";
    else
    	s = res.substr(1, res.length() - 1);
}

int main() {
    string s;
    //s = "the key is blue";
    s = " ";
    cout << "*" << s << "*" << endl;
    reverseWords(s);
    cout << "*" << s << "*" << endl;
    return 0;
}
