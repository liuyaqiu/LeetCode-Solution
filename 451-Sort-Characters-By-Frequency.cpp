#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct comp {
    bool operator() (const pair<char, int>& lhs, const pair<char, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

string frequencySort(string s) {
    map<char, int> cnt;
    for(int i = 0; i < s.length(); i++) {
        if(cnt.find(s[i]) == cnt.end())
            cnt[s[i]] = 1;
        else
            cnt[s[i]] += 1;
    }
    vector<pair<char, int>> chars;
    for(auto item: cnt)
        chars.push_back(pair<int, int>(item.first, item.second));
    sort(chars.begin(), chars.end(), comp());
    string res = "";
    for(auto item: chars) {
        for(int i = 0; i < item.second; i++)
            res += item.first;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    string res = frequencySort(s);
    cout << res << endl;
    return 0;
}
