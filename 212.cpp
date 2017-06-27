#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    string item;
    TrieNode(): children(vector<TrieNode*>(26, NULL)), item("") {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++) {
            char c = word[i];
            if(node->children[c - 'a'] == NULL)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->item = word;
    }

    bool search(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++) {
            char c = word[i];
            if(node->children[c - 'a'] == NULL)
                return false;
            node = node->children[c - 'a'];
        }
        if(node->item == word)
            return true;
        else
            return false;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i = 0; i < prefix.length(); i++) {
            char c = prefix[i];
            if(node->children[c - 'a'] == NULL)
                return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string str, int i, int j, Trie& trie, set<string>& result) {
    int m = board.size();
    int n = board[0].size();
    if(i < 0 || j < 0 || i >= m || j >= n)
        return;
    if(visited[i][j])
        return;
    str = str + board[i][j];
    if(!trie.startsWith(str))
        return;
    if(trie.search(str)) {
        result.insert(str);
    }
    visited[i][j] = true;
    dfs(board, visited, str, i - 1, j, trie, result);
    dfs(board, visited, str, i + 1, j, trie, result);
    dfs(board, visited, str, i, j - 1, trie, result);
    dfs(board, visited, str, i, j + 1, trie, result);
    visited[i][j] = false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie = Trie();
    for(auto iter = words.begin(); iter != words.end(); iter++)
        trie.insert(*iter);
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    set<string> result;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            dfs(board, visited, "", i, j, trie, result);
    }
    vector<string> res(result.begin(), result.end());
    return res;
}

void print(vector<string>& words) {
    for(auto iter = words.begin();iter != words.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board;
    for(int i = 0; i < m; i++) {
        vector<char> tmp;
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            tmp.push_back(c);
        }
        board.push_back(tmp);
    }
    vector<string> words;
    string s;
    while(cin >> s) {
        words.push_back(s);
    }
    vector<string> res = findWords(board, words);
    print(res);
    return 0;
}
