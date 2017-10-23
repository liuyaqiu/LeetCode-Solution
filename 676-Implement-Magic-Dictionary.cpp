/*
  Implement Magic Dictionary

  Implement a magic directory with buildDict, and search methods.

  For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

  For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

  Example 1:
  Input: buildDict(["hello", "leetcode"]), Output: Null
  Input: search("hello"), Output: False
  Input: search("hhllo"), Output: True
  Input: search("hell"), Output: False
  Input: search("leetcoded"), Output: False
  Note:
  You may assume that all the inputs are consist of lowercase letters a-z.
  For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
  Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.

 */

#include <iostream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    int k; // can have k different chars at most
    vector<TrieNode*> children;
    vector<bool> endOfWord;

    TrieNode(int x=1): k(x), children(vector<TrieNode*>(ALPHABET_SIZE, NULL)), endOfWord(vector<bool>(ALPHABET_SIZE, false)) {}

    void insert(string word, int pos) {
        if(pos >= word.size())
            return;
        int index = word[pos] - 'a';
        if(pos == word.size() - 1)
            endOfWord[index] = true;
        if(children[index] == NULL)
            children[index] = new TrieNode();
        children[index]->insert(word, pos + 1);
    }

    bool query(string word, int pos, int delta) {
        //如果不同字符数量已经超过，那么返回false
        if(delta > k)
            return false;
        if(pos >= word.size())
            return false;
        int index = word[pos] - 'a';
        if(pos == word.size() - 1) {
            for(int i = 0; i < endOfWord.size(); i++) {
                if(endOfWord[i]) {
                    if(i == index && delta == k)
                        return true;
                    if(i != index && delta == k - 1)
                        return true;
                }
            }
            return false;
        }
        for(int i = 0; i < children.size(); i++) {
            int tmp = delta;
            //当此后路径查询字符与目标字符不同时，delta应该加一
            if(i != index)
                tmp += 1;
            if(children[i] != NULL && children[i]->query(word, pos + 1, tmp))
                return true;
        }
        return false;
    }
};

class MagicDictionary {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto word: dict)
            root->insert(word, 0);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return root->query(word, 0, 0);
    }
};
