#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
 * Remove Duplicate Letters
 *
 * Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
 *
 * Example:
 * Given "bcabc"
 * Return "abc"
 *
 * Given "cbacdcbc"
 * Return "acdb"
 *
 *
 */

string removeDuplicateLetters(string s) {
    string res;
    vector<list<int>> pos(26, list<int>());
    for(int i = 0; i < s.length(); i++) {
        int k = s[i] - 'a';
        pos[k].push_back(i);
    }
    bool judge = true;
    vector<int> result;
    while(judge) {
        int m = -1;
        for(int i = 0; i < 26; i++) {
            if(!pos[i].empty()) {
                bool tmp = true;
                int p = pos[i].front();
                for(int j = 0; j < 26; j++) {
                    if(j != i && !pos[j].empty() && pos[j].back() < p) {
                            tmp = false;
                            break;
                        }
                }
                if(tmp){
                    m = i;
                    break;
                }
            }
        }
        if(m != -1) {
            int p = pos[m].front();
            result.push_back(p);
            pos[m].clear();
            for(int i = 0; i < 26; i++) {
                while(!pos[i].empty() && pos[i].front() < p) {
                    pos[i].pop_front();
                }
            }
        }
        else
            judge = false;
    }
    for(auto i: result)
        res = res + s[i];
    return res;
}

int main() {
    string s;
    cin >> s;
    string res = removeDuplicateLetters(s);
    cout << res << endl;
    return 0;
}
