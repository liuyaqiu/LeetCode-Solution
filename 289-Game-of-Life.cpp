#include <iostream>
#include <vector>

using namespace std;

/*
 * Game of Life
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 *
 * Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 * Any live cell with two or three live neighbors lives on to the next generation.
 * Any live cell with more than three live neighbors dies, as if by over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 * Write a function to compute the next state (after one update) of the board given its current state.
 *
 * Follow up: 
 * Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 *
 *
 */

void update(vector<vector<int>>& board, int x, int y) {
    int m = board.size();
    int n = board[0].size();
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int p = x + i, q = y + j;
            if(!(p == x && q == y) && (p >= 0 && p < m) && (q >= 0) && q < n) {
                if(board[p][q] > 0) {
                    if(board[x][y] > 0)
                        board[x][y] += 1;
                    else
                        board[x][y] -= 1;
                }
            }
        }
    }
}

int eval(vector<vector<int>>& board, int i, int j) {
    int val = board[i][j];
    if(val == 1 || val == 2)
        return 0;
    if(val == 3 || val == 4)
        return 1;
    if(val > 4)
        return 0;
    if(val == -3)
        return 1;
    return 0;
}

void gameOfLife(vector<vector<int>>& board) {
    if(board.empty())
        return;
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            update(board, i, j);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = eval(board, i, j);
        }
    }
}
