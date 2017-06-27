#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool search(string word, unordered_set<string>& words) {
    if(words.find(word) != words.end())
        return true;
    int n = word.length();
    for(int i = 1; i < n; i++) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i, n - i);
        if(words.find(prefix) != words.end() && search(suffix, words))
            return true;
    }
    return false;
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> res;
    unordered_set<string> wordSet(words.begin(), words.end());
    for(auto word: words) {
        wordSet.erase(word);
        if(search(word, wordSet))
            res.push_back(word);
        wordSet.insert(word);
    }
    return res;
}

int main() {
    string str;
    vector<string> words;
    while(cin >> str)
        words.push_back(str);
    vector<string> res = findAllConcatenatedWordsInADict(words);
    for(auto str: res)
        cout << str << " ";
    cout << endl;
    return 0;
}
