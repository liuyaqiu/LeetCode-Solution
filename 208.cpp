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

class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node('0');
        }

        void insert(string word) {
            if(word.empty())
                return;
            int i = 0;
            Node* cur = root;
            while(i < word.length()) {
                if(cur->child.find(word[i]) != cur->child.end()) {
                    cur = cur->child[word[i]];
                    i++;
                }
                else
                    break;
            }
            while(i < word.length()) {
                Node* tmp = new Node(word[i]);
                cur->child[word[i]] = tmp;
                cur = tmp;
                i++;
            }
            cur->end = true;
        }

        bool search(string word) {
            int i = 0;
            Node* cur = root;
            while(i < word.length()) {
                if(cur->child.find(word[i]) != cur->child.end()) {
                    cur = cur->child[word[i]];
                    i++;
                }
                else
                    return false;
            }
            return cur->end;
        }

        bool startsWith(string prefix) {
            int i = 0;
            Node* cur = root;
            while(i < prefix.length()) {
                if(cur->child.find(prefix[i]) != cur->child.end()) {
                    cur = cur->child[prefix[i]];
                    i++;
                }
                else
                    return false;
            }
            return true;
        }
};

int main() {
    Trie obj = Trie();
    string word1 = "apple";
    string word2 = "application";
    obj.insert(word1);
    bool res1 = obj.search(word1);
    bool res2 = obj.startsWith(word1);
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}
