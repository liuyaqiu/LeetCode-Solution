/*
  Map Sum Pairs

  Implement a MapSum class with insert, and sum methods.

  For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

  For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

  Example 1:
  Input: insert("apple", 3), Output: Null
  Input: sum("ap"), Output: 3
  Input: insert("app", 2), Output: Null
  Input: sum("ap"), Output: 5

 */

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int ALPHASET_SIZE = 26;

struct TrieNode {
    vector<TrieNode*> children;
    vector<set<string>> words;

    TrieNode(): children(vector<TrieNode*>(ALPHASET_SIZE, NULL)), words(vector<set<string>>(ALPHASET_SIZE, set<string>())) {};

    void insert(string key, int val, int pos) {
        if(pos >= key.length())
            return;
        int index = key[pos] - 'a';
        words[index].insert(key);
        if(children[index] == NULL)
            children[index] = new TrieNode();
        children[index]->insert(key, val, pos + 1);
    }

    set<string> search(string key, int pos) {
        if(pos >= key.length())
            return {};
        int index = key[pos]  - 'a';
        if(pos == key.length() - 1)
            return words[index];
        if(children[index] == NULL)
            return {};
        else
            return children[index]->search(key, pos + 1);
    }

};

class MapSum {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    map<string, int> values;

    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        if(values.find(key) == values.end())
            root->insert(key, val, 0);
        values[key] = val;
    }

    int sum(string prefix) {
        set<string> keys = root->search(prefix, 0);
        int res = 0;
        for(auto item: keys)
            res += values[item];
        return res;
    }
};
