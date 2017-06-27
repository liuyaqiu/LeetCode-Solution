#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> convert;
    unordered_set<char> used;
    if(s.length() != t.length())
        return false;
    for(int i = 0; i < s.length(); i++) {
        if(convert.find(s[i]) != convert.end()) {
            if(t[i] != convert[s[i]])
                return false;
        }
        else {
        	if(used.find(t[i]) != used.end())
        		return false;
        	else {
                used.insert(t[i]);
            	convert[s[i]] = t[i];
            }
        }
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    bool res = isIsomorphic(s, t);
    if(res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
