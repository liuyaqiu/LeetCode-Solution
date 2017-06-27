#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void print(vector<vector<char>>& board) {
    for(auto iter1 = board.begin(); iter1 != board.end(); iter1++) {
        for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++)
            cout << *iter2 <<" ";
        cout << endl;
    }
    cout << endl;
}

void bfsUtil(int start, vector<vector<char>>& board, vector<vector<char>>& tmp, vector<int>& visit) {
    int n = board[0].size();
    int m = board.size();
    queue<int> neighbors;
    if(board[start / n][start % n] == 'O' && !visit[start])
    	neighbors.push(start);
    else
    	return;
    while(!neighbors.empty()) {
        int pos = neighbors.front();
        neighbors.pop();
        int x = pos % n;
        int y = pos / n;
        tmp[y][x] = 'O';
        //cout << "Pos: " << y << ", "<< x << endl;
        visit[pos] = true;
        for(int i = -1; i <= 1; i += 2) {
            int cx = x + i;
            if(cx >= 0 && cx < n && board[y][cx] == 'O') {
                if(!visit[y * n + cx]) {
                    visit[y * n + cx] = true;
                    neighbors.push(y * n + cx);
                }
            }
        }
        for(int j = -1; j <= 1; j+=2) {
            int cy = y + j;
            if(cy >= 0 && cy < m && board[cy][x] == 'O') {
                if(!visit[cy * n + x]) {
                    visit[cy * n + x] = true;
                    neighbors.push(cy * n + x);
                }
            }
        }
    }
}

void printVec(vector<int> visit) {
	for(auto iter = visit.begin(); iter != visit.end(); iter++)
    	cout << *iter << " ";
    cout << endl;
}

void solve(vector<vector<char>>& board) {
	if(board.empty())
		return;
    int m = board.size();
    int n = board[0].size();
    vector<int> visit(m * n, false);
    vector<vector<char>> tmp(m, vector<char>(n, 'X'));
    for(int i = 0; i < n; i++) {
        bfsUtil(i, board, tmp, visit);
    }
    for(int j = 0; j < n; j++) {
    	bfsUtil(j * n, board, tmp, visit);
    }
    for(int j = 0; j < m; j++) {
        bfsUtil(j * n + n - 1, board, tmp, visit);
    }
    for(int i = 0; i < n; i++) {
        bfsUtil((m - 1) * n + i, board, tmp, visit);
    }
    board = tmp;
}

int main() {
    //int m, n;
    //cout << "Input row nums and col nums: ";
    //cin >> m >> n;
    vector<string> input = {"XOOOOOOOOOOOOOOOOOOO","OXOOOOXOOOOOOOOOOOXX","OOOOOOOOXOOOOOOOOOOX","OOXOOOOOOOOOOOOOOOXO","OOOOOXOOOOXOOOOOXOOX","XOOOXOOOOOXOXOXOXOXO","OOOOXOOXOOOOOXOOXOOO","XOOOXXXOXOOOOXXOXOOO","OOOOOXXXXOOOOXOOXOOO","XOOOOXOOOOOOXXOOXOOX","OOOOOOOOOOXOOXOOOXOX","OOOOXOXOOXXOOOOOXOOO","XXOOOOOXOOOOOOOOOOOO","OXOXOOOXOXOOOXOXOXOO","OOXOOOOOOOXOOOOOXOXO","XXOOOOOOOOXOXXOOOXOO","OOXOOOOOOOXOOXOXOXOO","OOOXOOOOOXXXOOXOOOXO","OOOOOOOOOOOOOOOOOOOO","XOOOOXOOOXXOOXOXOXOO"};
    int m = input.size();
    int n = input[0].length();
    vector<vector<char>> board;
    for(int i = 0; i < m; i++) {
        vector<char> row;
        char val;
        for(int j = 0; j < n; j++) {
            //cin >> val;
            val = input[i][j];
            row.push_back(val);
        }
        board.push_back(row);
    }
    print(board);
    solve(board);
    print(board);
    return 0;
}

