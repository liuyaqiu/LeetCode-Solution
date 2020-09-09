/*
 * Longest Common Prefix
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if(strs.empty())
		return "";
    if(strs.size() == 1)
        return strs[0];
    int pos = 0;
    char cur = strs[0][pos];
    bool get = false;
    while(true) {
        for(int i = 1; i < strs.size(); i += 1) {
            if(pos >= strs[i].length() || cur != strs[i][pos]) {
                get = true;
                break;
            }
        }
        if(get)
            break;
        else {
            pos += 1;
            if(pos >= strs[0].length())
                break;
            cur = strs[0][pos];
        }
    }
    return strs[0].substr(0, pos);
}

int main() {
	vector<string> strs;
	strs.push_back("a");
	strs.push_back("b");
	cout << longestCommonPrefix(strs) << endl;
	return 0;
}
