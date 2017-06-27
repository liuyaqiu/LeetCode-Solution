#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
    char label;
    bool end;
    unordered_map<char, Node*> child;
    Node(char c): label(c), end(false), child(unordered_map<char, Node*>()) {}
};

class WordDictionary {
private:
    Node* root;
    unordered_map<string, bool> cache;
    int max_size;

public:
    WordDictionary() {
        root = new Node('0');
        max_size = 100;
    }

    void addWord(string word) {
    	cache.clear();
        Node* cur = root;
        int i = 0;
        while(i < word.length() && cur->child.find(word[i]) != cur->child.end()) {
            cur = cur->child[word[i]];
            i++;
        }
        while(i < word.size()) {
            Node* tmp = new Node(word[i]);
            cur->child[word[i]] = tmp;
            cur = tmp;
            i++;
        }
        cur->end = true;
    }

    bool search(string word) {
        if(cache.find(word) != cache.end())
            return cache[word];
        else {
            if(cache.size() >= max_size)
                cache.erase(cache.begin());
            bool res = dfsSearch(root->child, word, 0);
            cache[word] = res;
            return res;
        }
    }

    bool dfsSearch(unordered_map<char, Node*> child, string word, int start) {
        if(word == ".") {
            for(auto iter = child.begin(); iter != child.end(); iter++) {
                if(iter->second->end)
                    return true;
            }
            return false;
        }
        if(start == word.length())
            return child.size() == 0;
        char c = word[start];
        if(child.find(c) != child.end()) {
            if(start == word.length() - 1 && child[c]->end)
                return true;
            return dfsSearch(child[c]->child, word, start + 1);
        }
        else if(c == '.') {
            bool res = false;
            for(auto iter = child.begin(); iter != child.end(); iter++) {
                if(start == word.length() - 1 && iter->second->end)
                    return true;
                if(dfsSearch(iter->second->child, word, start + 1))
                    return true;
            }
            return res;
        }
        else
            return false;
    }
};
