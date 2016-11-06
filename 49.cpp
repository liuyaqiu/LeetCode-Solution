#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

string getKey(string str) {
    vector<char> key;
    for(auto iter = str.begin(); iter != str.end(); iter += 1) {
        key.push_back(*iter);
    }
    sort(key.begin(), key.end());
    string res;
    for(auto iter = key.begin(); iter != key.end(); iter += 1) {
        res += *iter;
    }
    return res;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> the_res;
    for(auto iter = strs.begin(); iter != strs.end(); ++iter) {
        string key = getKey(*iter);
        auto map_iter = the_res.find(key);
        if(map_iter == the_res.end()) {
            vector<string> tmp(1, *iter);
            the_res.insert(pair<string, vector<string>>(key, tmp));
        }
        else {
            map_iter->second.push_back(*iter);
        }
    }
    vector<vector<string>> res;
    for(auto iter = the_res.begin(); iter != the_res.end(); ++iter) {
        res.push_back(iter->second);
    }
    return res;
}

void print(vector<string>& res) {
    for(auto iter = res.begin(); iter != res.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Please input the num: ";
    cin >> n;
    string s;
    vector<string> strs;
    while(n > 0) {
        cin >> s;
        strs.push_back(s);
        n -= 1;
    }
    vector<vector<string>> res = groupAnagrams(strs);
    for(auto iter = res.begin(); iter != res.end(); ++iter) {
        print(*iter);
    }
    return 0;
}
