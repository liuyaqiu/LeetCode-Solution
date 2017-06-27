#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

/*
 * Word Pattern
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 *
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 *
 *
 */
string convert(string str) {
    string res = str.substr(0, 1);
    for(int i = 1; i < str.length(); i++) {
        res += ' ';
        res += str[i];
    }
    return res;
}

int nextSpace(string str, int i) {
    while(i < str.length() && str[i] != ' ')
        i++;
    return i;
}

bool wordPattern(string pattern, string str) {
    string p = convert(pattern);
    map<string, int> p_refer;
    map<string, int> s_refer;
    int ip = 0, is = 0;
    int np = p.length(), ns = str.length();
    while(ip < np && is < ns) {
        int jp = nextSpace(p, ip);
        string p_cur = p.substr(ip, jp - ip);
        if(p_refer.find(p_cur) == p_refer.end()) {
            int size = p_refer.size();
            p_refer[p_cur] = size;
        }
        int js = nextSpace(str, is);
        string s_cur = str.substr(is, js - is);
        if(s_refer.find(s_cur) == s_refer.end()) {
            int size = s_refer.size();
            s_refer[s_cur] = size;
        }
        if(p_refer[p_cur] != s_refer[s_cur])
            return false;
        ip = jp + 1;
        is = js + 1;
    }
    return ip >= np && is >= ns;
}

int main() {
    string p, s;
    p = "abba";
    s = "dog cat cat dog";
    bool res = wordPattern(p, s);
    cout << res << endl;
    return 0;
}
