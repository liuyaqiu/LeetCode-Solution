#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define eraser 0x03ffff

int toNum(char c) {
    if(c == 'A')
        return 0;
    else if(c == 'C')
        return 1;
    else if(c == 'G')
        return 2;
    else
        return 3;
}

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    if(s.length() < 10)
        return res;
    unordered_set<unsigned int> repeated, check;
    int hash = 0;
    for(int i = 0; i < 10; i++) {
        hash = (hash << 2) + toNum(s[i]);
    }
    repeated.insert(hash);
    for(int i = 10; i < s.length(); i++) {
        hash = ((hash & eraser) << 2) + toNum(s[i]);
        auto iter = repeated.find(hash);
        if(iter == repeated.end()) {
            repeated.insert(hash);
        }
        else {
            iter = check.find(hash);
            if(iter == check.end()) {
                res.push_back(s.substr(i - 9, 10));
                check.insert(hash);
            }
        }
    }
    return res;
}

