#include <iostream>
#include <vector>

using namespace std;

int countBattleships(vector<vector<char>>& board) {
    if(board.empty())
        return 0;
    int res = 0;
    int m = board.size();
    int n = board.front().size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'X') {
                if(i > 0 && board[i - 1][j] == 'X')
                    continue;
                if(j > 0 && board[i][j - 1] == 'X')
                    continue;
                res += 1;
            }
        }
    }
    return res;
}
