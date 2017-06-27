#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

char convert(char c) {
    if(c - 'A' >= 0 && c - 'A' < 26)
        return (c - 'A') + 'a';
    else
        return c;
}

bool judge(string word, const vector<unordered_set<char>>& rows) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < word.length(); i++) {
        char c = convert(word[i]);
        if(rows[0].find(c) != rows[0].end()) {
            if(cnt1 != 0 || cnt2 != 0)
                return false;
            else
                cnt0 += 1;
        }
        else if(rows[1].find(c) != rows[1].end()) {
            if(cnt0 != 0 || cnt2 != 0)
                return false;
            else
                cnt1 += 1;
        }
        else if(rows[2].find(c) != rows[2].end()){
            if(cnt0 != 0 || cnt1 != 0)
                return false;
            else
                cnt2 += 1;
        }
    }
    return true;
}

vector<string> findWords(vector<string>& words) {
    unordered_set<char> row1{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> row3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    vector<unordered_set<char>> rows{row1, row2, row3};
    vector<string> res;
    for(auto word: words) {
        if(judge(word, rows))
            res.push_back(word);
    }
    return res;
}
