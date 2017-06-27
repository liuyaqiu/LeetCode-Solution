#include <iostream>
#include <vector>

using namespace std;

bool repeatedSubstringPattern(string s) {
    int delta = 1;
    int n = s.length();
    while(delta <= n / 2) {
    	bool judge = true;
        for(int start = 0; start < delta; start++) {
            for(int pos = start + delta; pos < n; pos += delta) {
                if(s[pos] != s[start]) {
                	judge = false;
                    break;
                }
            }
        }
        if(judge)
        	return true;
        else {
        	delta++;
        	while(n % delta != 0)
        		delta++;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    bool res = repeatedSubstringPattern(s);
    cout << res << endl;
    return 0;
}
