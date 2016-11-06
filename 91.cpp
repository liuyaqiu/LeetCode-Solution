#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> reverseStr(string s) {
    vector<int> res;
    for(auto iter = s.rbegin(); iter != s.rend(); ++iter) {
        res.push_back(*iter - '0');
    }
    return res;
}

int numDecodings(string s) {
    if(s.empty())
        return 0;
    if(s.length() == 1) {
        if(s[0] == '0')
            return 0;
        else
            return 1;
    }
    int pre = 1, cur = 1;
    vector<int> rev = reverseStr(s);
    int i = 0;
    while(i < rev.size()) {
        if(rev[i] == 0) {
            if(rev[i + 1] == 1 || rev[i + 1] == 2) {
                i += 2;
                pre = cur;
            }
            else
                return 0;
        }
        else {
            if(i >= 2 && rev[i - 2] == 0) {
                pre = cur;
            }
            else {
                if(i == 0) {
                    pre = cur;
                }
                else {
		            if(rev[i] == 1) {
		                int tmp = cur;
		                cur += pre;
		                pre = tmp;
		            }
		            else if(rev[i] == 2) {
		                if(rev[i - 1] <= 6) {
		                    int tmp = cur;
		                    cur += pre;
		                    pre = tmp;
		                }
		            }
		            else
		                pre = cur;
                }
            }
            i += 1;
        }
    }
    return cur;
}

int main() {
    string s;
    cin >> s;
    cout << numDecodings(s) << endl;
    return 0;
}
