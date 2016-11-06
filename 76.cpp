#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <utility>

using namespace std;

void printMap(unordered_map<char, int> judge) {
    for(auto iter = judge.begin(); iter != judge.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
}

bool yes(unordered_map<char, int>& judge) {
    for(auto iter = judge.begin(); iter != judge.end(); ++iter)
        if(iter->second < 0)
            return false;
    return true;
}

vector<int> getPos(string s, string t) {
    set<char> symbol;
    for(int i = 0; i < t.length(); ++i) {
        if(symbol.find(t[i]) == symbol.end())
            symbol.insert(t[i]);
    }
    vector<int> pos;
    for(int i = 0; i < s.length(); ++i) {
        if(symbol.find(s[i]) != symbol.end())
            pos.push_back(i);
    }
    return pos;
}

unordered_map<char, int> getMap(string t) {
    unordered_map<char, int> the_map;
    for(int i = 0; i < t.length(); ++i) {
        auto iter = the_map.find(t[i]);
        if(iter == the_map.end())
            the_map.insert(pair<char, int>(t[i], -1));
        else
            iter->second -= 1;
    }
    return the_map;
}

string minWindow(string s, string t) {
    vector<int> pos = getPos(s, t);
    unordered_map<char, int> judge = getMap(t);
    int start = 0;
    int end = 0;
    int min = 0;
    string res;
    if(pos.empty())
    	return res;
    while(end < pos.size() && !yes(judge)) {
        char cur = s[pos[end]];
        auto iter = judge.find(cur);
        iter->second += 1;
        end += 1;
    }
    if(!yes(judge))
        return res;
    while(start < pos.size()) {
        if(min == 0 || min > pos[end - 1] - pos[start] + 1) {
            min = pos[end - 1] - pos[start] + 1;
            res = s.substr(pos[start], min);
        }
        char cur = s[pos[start]];
        auto iter = judge.find(cur);
        iter->second -= 1;
        start += 1;
        if(iter->second >= 0)
            continue;
        while(end < pos.size() && s[pos[end]] != cur) {
            char c = s[pos[end]];
            auto iter = judge.find(c);
            iter->second += 1;
            end += 1;
        }
        if(end >= pos.size()) {
            if(!yes(judge))
                break;
        }
        else {
            char c = s[pos[end]];
            auto iter = judge.find(c);
            iter->second += 1;
            end += 1;
        }
    }
    return res;
}

int main() {
    string s, t;
    cout << "Please input s and t: ";
    cin >> s >> t;
    cout << "The min window is: " << minWindow(s, t) << endl;
    return 0;
}
