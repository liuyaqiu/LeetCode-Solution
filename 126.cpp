#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct WordNode {
    string word;
    int numSetp;
    WordNode* pre;
    WordNode(string wd, int num, WordNode* p): word(wd), numSetp(num), pre(p) {}
};

void removeAll(unordered_set<string>& seta, unordered_set<string>& setb) {
    for(auto iter = setb.begin(); iter != setb.end(); iter++) {
        seta.erase(*iter);
    }
}

void print(vector<vector<string>>& res) {
    for(auto iter1 = res.begin(); iter1 != res.end(); iter1++) {
        for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++)
            cout << *iter2 << " ";
        cout << endl;
    }
    cout << endl;
}
vector<vector<string>> findLadders(string start, string end, unordered_set<string>& dict) {
    vector<vector<string>> result;
    queue<WordNode*> que;
    que.push(new WordNode(start, 1, NULL));
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
            }
            if(top->numSetp == minSetp && minSetp != 0) {
                vector<string> t;
                t.push_back(top->word);
                while(top->pre != NULL) {
                    t.insert(t.begin(), top->pre->word);
                    top = top->pre;
                }
                result.push_back(t);
                continue;
            }
        }
        if(preNumStep < curNumStep) {   //访问当前层节点时，依次将下一层的节点标记为已经访问，然后当下一层的节点被访问时，将该层的节点从未访问节点中移除（即保证不会返回前层节点）
            removeAll(unvisited, visited);
        }
        preNumStep = curNumStep;
        for(int i = 0; i < word.length(); i++) {
            for(char c = 'a'; c <= 'z'; c++) {
                char temp = word[i];
                if(temp != c)
                    word[i] = c;
                if(unvisited.find(word) != unvisited.end()) {
                    que.push(new WordNode(word, top->numSetp + 1, top));
                    visited.insert(word);
                }
                word[i] = temp;
            }
        }
    }
    return result;
}

int main() {
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    unordered_set<string> wordList;
    string val;
    while(cin >> val) {
        wordList.insert(val);
    }
    vector<vector<string>> res = findLadders(beginWord, endWord, wordList);
    print(res);
    return 0;
}

