#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

typedef pair<int, int> Pair;

void print(vector<vector<char>> board) {
    for(auto iter = board.begin(); iter != board.end(); ++iter) {
        for(auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
            cout << *iter2 << " ";
        cout << endl;
    }
}
void print2(vector<vector<bool>> board) {
    for(auto iter = board.begin(); iter != board.end(); ++iter) {
        for(auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
            if(*iter2)
                cout << "true" << " ";
            else
                cout << "false" << " ";
        cout << endl;
    }
}


int getPos(Pair p, int len) {
    return p.second * len + p.first;
}

Pair getPair(int pos, int len) {
    return Pair(pos % len, pos / len);
}

Pair nextPair(Pair p, int m, int n, vector<vector<bool>>& use, int& status) {
    int x = p.first, y = p.second;
    while(true) {
        if(status == 0) {
            status += 1;
            if(x - 1 >= 0 && !use[y][x - 1])
                return Pair(x - 1, y);
        }
        else if(status == 1){
            status += 1;
            if(y - 1 >= 0 && !use[y - 1][x])
                return Pair(x, y - 1);
        }
        else if(status == 2) {
            status += 1;
            if(x + 1 < n && !use[y][x + 1])
                return Pair(x + 1, y);
        }
        else if(status == 3) {
            status += 1;
            if(y + 1 < m && !use[y + 1][x])
                return Pair(x, y + 1);
        }
        else {
            return Pair(-1, -1);
        }
    }
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> use(m, vector<bool>(n, false));
    stack<Pair> path;
    stack<int> status;
    int pos = 0;
    Pair p;
    while(true) {
        int cnt = path.size();
        //cout << "Cnt: " << cnt << endl;
        if(cnt == 0) {
            while(pos < m * n) {
                p = getPair(pos, n);
                if(board[p.second][p.first] == word[cnt])
                    break;
                else
                    pos += 1;
            }
            if(pos >= m * n)
                return false;
            p = getPair(pos, n);
            use[p.second][p.first] = true;
            status.push(0);
            path.push(p);
        }
        else if(cnt < word.length()) {
            Pair last = path.top();
            //cout << last.first << " " << last.second << endl;
            Pair t = nextPair(last, m, n, use, status.top());
            //cout << status.top() << endl;
            //print2(use);
            //cout << "Point 1" << endl;
            while(t != Pair(-1, -1) && board[t.second][t.first] != word[cnt]) {
                t = nextPair(last, m, n, use, status.top());
            }
            //cout << "Point 2" << endl;
            if(t == Pair(-1, -1)) {
                use[last.second][last.first] = false;
                path.pop();
                status.pop();
                pos = getPos(p, n) + 1;
            }
            else {
                use[t.second][t.first] = true;
                path.push(t);
                status.push(0);
            }
        }
        else
            return true;
    }
}

int main() {
    int m, n;
    cout << "Please input m and n: ";
    cin >> m >> n;
    char val;
    vector<vector<char>> board(m, vector<char>(n, ' '));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> val;
            board[i][j] = val;
        }
    }
    print(board);
    string word;
    while(true) {
        cout << "input the word: ";
        cin >> word;
        bool e = exist(board, word);
        if(e)
            cout << "Word Exist" << endl;
        else
            cout << "Word not exist" << endl;
    }
    return 0;
}

