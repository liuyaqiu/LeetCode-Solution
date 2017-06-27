#include <iostream>
#include <vector>
#include <unordered_set> 
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

void neighbors(string s, unordered_set<string>& visit, queue<string>& next, unordered_map<string, unordered_set<string>>& bucket) {
    for(int i = 0; i < s.length(); i++) {
        string tmp = s;
        tmp[i] = '_';
        for(auto iter = bucket[tmp].begin(); iter != bucket[tmp].end(); iter++) {
            if(visit.find(*iter) == visit.end()) {
                visit.insert(*iter);
                next.push(*iter);
            }
        }
    }
}

int shortest(string start, string end, unordered_map<string, unordered_set<string>>& bucket) {
    unordered_set<string> visit;
    visit.insert(start);
    queue<string> cur;
    queue<string> next;
    int path = 1;
    cur.push(start);
    while(!cur.empty()) {
        string tmp = cur.front();
        if(tmp == end)
            break;
        cur.pop();
        neighbors(tmp, visit, next, bucket);
        if(cur.empty()) {
            cur = next;
            next = queue<string>();
            path++;
        }
    }
    if(cur.empty())
        return 0;
    else
        return path;
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    wordList.insert(beginWord);
    wordList.insert(endWord);
    unordered_map<string, unordered_set<string>> bucket;
    for(auto iter = wordList.begin(); iter != wordList.end(); iter++) {
        for(int i = 0; i < iter->length(); i++) {
            string tmp = *iter;
            tmp[i] ='_';
            auto ftmp = bucket.find(tmp);
            if(ftmp == bucket.end()) {
                unordered_set<string> t;
                t.insert(*iter);
                bucket[tmp] = t;
            }
            else {
                ftmp->second.insert(*iter);
            }
        }
    }
    return shortest(beginWord, endWord, bucket);
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

