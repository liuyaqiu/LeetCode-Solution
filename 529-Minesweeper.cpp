#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> mypair;

int eval(vector<vector<char>>& board, int x, int y) {
    int m = board.size(), n = board[0].size();
    int cnt = 0;
    for(int i = x - 1; i <= x + 1; i++) {
        for(int j = y - 1; j <= y + 1; j++) {
            if(i >= 0 && i < m && j >= 0 && j < n) {
                if(!(i == x && j == y)) {
                    if(board[i][j] == 'M')
                        cnt++;
                }
            }
        }
    }
    return cnt;
}

void reveal(vector<vector<char>>& board, int x, int y) {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    int tmp = eval(board, x, y);
    if(tmp != 0) {
        board[x][y] = tmp + '0';
        return;
    }
    board[x][y] = 'B';
    queue<mypair> que;
    que.push(mypair(x, y));
    while(!que.empty()) {
        int index_x = que.front().first, index_y = que.front().second;
        que.pop();
        for(int i = index_x - 1; i <= index_x + 1; i++) {
            for(int j = index_y - 1; j <= index_y + 1; j++) {
                if(i >= 0 && i < m && j >= 0 && j < n) {
                    if(!(i == index_x && j == index_y) && !visit[i][j]) {
                        int cnt = eval(board, i, j);
                        if(cnt == 0) {
                            board[i][j] = 'B';
                            que.push(mypair(i, j));
                        }
                        else {
                            board[i][j] = cnt + '0';
                        }
                        visit[i][j] = true;
                    }
                }
            }
        }
    }
}


vector<vector<char>> updateBoard(vector<vector<char>>& board, const vector<int>& click) {
    int i = click[0], j = click[1];
    if(board[i][j] == 'M') {
        board[i][j] = 'X';
    }
    else if(board[i][j] == 'E') {
        reveal(board, i, j);
    }
    return board;
}

void print(vector<vector<char>>& board) {
    for(auto row: board) {
        for(auto item: row)
            cout << item << " "; 
        cout << endl;
    }
    cout << endl;
}

int main() {
    int m, n;
    cin >> m >> n;
    char c;
    vector<vector<char>> board(m, vector<char>(n, '0'));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c;
            board[i][j] = c;
        }
    }
    print(board);
    int x, y;
    cin >> x >> y;
    updateBoard(board, {x, y});
    print(board);
    return 0;
}
