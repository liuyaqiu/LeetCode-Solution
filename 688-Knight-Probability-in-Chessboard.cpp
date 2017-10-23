/*
  Knight Probability in Chessboard

  On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

  A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

  Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

  The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

  Example:
  Input: 3, 2, 0, 0
  Output: 0.0625
  Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
  From each of those positions, there are also two moves that will keep the knight on the board.
  The total probability the knight stays on the board is 0.0625.
  Note:
  N will be between 1 and 25.
  K will be between 0 and 100.
  The knight always initially starts on the board.

 */

#include <iostream>
#include <vector>

using namespace std;

double eval(vector<vector<double>>& prev, int i, int j) {
    int N = prev.size();
    double res = 0;
    for(int dx = -2; dx <= 2; dx++) {
        for(int dy = -2; dy <= 2; dy++) {
            if(i + dx >= 0 && i + dx < N && j + dy >= 0 && j + dy < N && dx * dx + dy * dy == 5) {
                res += prev[i + dx][j + dy] * 1.0 / 8;
            }
        }
    }
    return res;
}

double knightProbability(int N, int K, int r, int c) {
    vector<vector<vector<double>>> res(K + 1, vector<vector<double>>(N, vector<double>(N, 0)));
    res[0] = vector<vector<double>>(N, vector<double>(N, 1));
    for(int k = 1; k <= K; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++)
                res[k][i][j] = eval(res[k - 1], i, j);
        }
    }
    return res[K][r][c];
}
