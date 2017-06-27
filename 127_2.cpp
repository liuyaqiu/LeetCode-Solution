#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct WordNode {
    string word;
    int numSetp;
    WordNode(string wd, int num): word(wd), numSetp(num) {}
};

void removeAll(unordered_set<string>& seta, unordered_set<string>& setb) {
    for(auto iter = setb.begin(); iter != setb.end(); iter++) {
        seta.erase(*iter);
    }
}

int ladderLength(string start, string end, unordered_set<string>& dict) {
    queue<WordNode*> que;
    que.push(new WordNode(start, 1));
    dict.insert(end);
    int minSetp = 0;
    unordered_set<string> visited;
    unordered_set<string> unvisited;
    unvisited = dict;
    int preNumStep = 0;
    while(!que.empty()) {
        WordNode* top = que.front();
        que.pop();
        string word = top->word;
        int curNumStep = top->numSetp;
        if(word == end) {
            if(minSetp == 0) {
                minSetp = top->numSetp;
                break;
            }
        }
        if(preNumStep < curNumStep) {
            removeAll(unvisited, visited);
        }
        preNumStep = curNumStep;
        for(int i = 0; i < word.length(); i++) {
            for(char c = 'a'; c <= 'z'; c++) {
                char temp = word[i];
                if(temp != c)
                    word[i] = c;
                if(unvisited.find(word) != unvisited.end()) {
                    que.push(new WordNode(word, top->numSetp + 1));
                    visited.insert(word);
                }
                word[i] = temp;
            }
        }
    }
    return minSetp;
}

int main() {
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    unordered_set<string> wordList;
    string val;
    while(cin >> val) {
        wordList.insert(val);
    }
    int res = ladderLength(beginWord, endWord, wordList);
    cout << res << endl;
    return 0;
}

