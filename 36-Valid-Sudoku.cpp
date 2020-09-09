/*
 * Valid Sudoku
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int len = board.size();
    for(int i = 0; i < len; i += 1) {
        vector<bool> judge(9, true);
        for(int j = 0; j < len; j += 1) {
            int pos = board[i][j] - '0';
            if(pos >= 0 && pos <= 9) {
                if(judge[pos] == false)
                    return false;
                else
                    judge[pos] = false;
            }
        }
    }
    for(int j = 0; j < len; j += 1) {
        vector<bool> judge(9, true);
        for(int i = 0; i < len; i += 1) {
            int pos = board[i][j] - '0';
            if(pos >= 0 && pos <= 9) {
                if(judge[pos] == false)
                    return false;
                else
                    judge[pos] = false;
            }
        }
    }
    for(int i = 0; i < len; i += 1) {
        int x = (i % 3) * 3;
        int y = (i / 3) * 3;
        vector<bool> judge(9, true);
        for(int j = 0; j < 3; j += 1) {
            for(int k = 0; k < 3; k += 1) {
                int pos = board[x + j][y + k] - '0';
                if(pos >= 0 && pos <= 9) {
                    if(judge[pos] == false)
                        return false;
                    else
                        judge[pos] = false;
                }
            }
        }
    }
    return true;
}
