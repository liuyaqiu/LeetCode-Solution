#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string split(string s, int& pos) {
    int end = pos + 1;
    while(end < s.length() && s[end] != '/')
        end += 1;
    int tmp = pos;
    pos = end;
    return s.substr(tmp + 1, end - tmp - 1);
}

string getRes(vector<string>& paths) {
    string res;
    if(paths.empty())
        return "/";
    for(auto iter = paths.begin(); iter != paths.end(); ++iter)
        res += "/" + *iter;
    return res;
}

string simplifyPath(string path) {
    vector<string> res;
    string cur;
    int pos = 0;
    while(pos < path.length()) {
        cur = split(path, pos);
        if(cur.empty())
            continue;
        if(cur == "..") {
            if(!res.empty())
                res.pop_back();
        }
        else if(cur == ".") {
        }
        else {
            res.push_back(cur);
        }
    }
    return getRes(res);
}

int main() {
    string path;
    cout << "Please input the path: ";
    cin >> path;
    cout << "The simplify path is: " << simplifyPath(path) << endl;
}
