/*
  Prefix and Suffix Search

  Given many words, words[i] has weight i.

  Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

  Examples:
  Input:
  WordFilter(["apple"])
  WordFilter.f("a", "e") // returns 0
  WordFilter.f("b", "") // returns -1
  Note:
  words has length in range [1, 15000].
  For each test case, up to words.length queries WordFilter.f may be made.
  words[i] has length in range [1, 10].
  prefix, suffix have lengths in range [0, 10].
  words[i] and prefix, suffix queries consist of lowercase letters only.

 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_set<string> contain;
    vector<TrieNode*> childs;
    TrieNode() {
        childs = vector<TrieNode*>(26, NULL);
    }
    unordered_set<string> query(string prefix, int k) {
        if(k >= prefix.size())
            return contain;
        int c = prefix[k] - 'a';
        if(childs[c] == NULL)
            return {};
        else
            return childs[c]->query(prefix, k + 1);
    }

    void insert(string word, int k) {
        contain.insert(word);
        if(k >= word.size())
            return;
        int c = word[k] - 'a';
        if(childs[c] == NULL)
            childs[c] = new TrieNode();
        childs[c]->insert(word, k + 1);
    }
};

class WordFilter {
private:
    TrieNode* trie_prefix;
    TrieNode* trie_suffix;
    unordered_map<string, int> index;

public:
    WordFilter(vector<string> words) {
        trie_prefix = new TrieNode();
        trie_suffix = new TrieNode();
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            index[word] = i;
            trie_prefix->insert(word, 0);
            string rev = word;
            reverse(rev.begin(), rev.end());
            trie_suffix->insert(rev, 0);
        }
    }

    int f(string prefix, string suffix) {
        unordered_set<string> pre = trie_prefix->query(prefix, 0);
        reverse(suffix.begin(), suffix.end());
        unordered_set<string> suf = trie_suffix->query(suffix, 0);
        unordered_set<string> merge;
        for(auto item: pre) {
            string rev = item;
            reverse(rev.begin(), rev.end());
            if(suf.find(rev) != suf.end())
                merge.insert(item);
        }
        int res = -1;
        for(auto item: merge)
            res = max(res, index[item]);
        return res;
    }
};
