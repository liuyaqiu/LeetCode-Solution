#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool canDelete(string s, string t) {
    int n1 = s.length(), n2 = t.length();
    int pos1 = 0, pos2 = 0;
    while(pos1 < n1 && pos2< n2) {
        while(pos1 < n1 && s[pos1] != t[pos2])
            pos1++;
        if(pos1 < n1) {
            pos1++;
            pos2++;
        }
    }
    return pos2 >= n2;
}

string findLongestWord(string s, vector<string>& d) {
    string res = "";
    for(auto t: d) {
        if(canDelete(s, t)) {
            if(res.empty())
                res = t;
            else {
                if(t.length() > res.length())
                    res = t;
                else if(t.length() == res.length() && t < res)
                    res = t;
            }
        }
    }
    return res;
}
