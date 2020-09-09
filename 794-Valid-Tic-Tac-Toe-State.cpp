class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x_count = 0;
        int o_count = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 'X') {
                    x_count += 1;
                } else if (board[i][j] == 'O') {
                    o_count += 1;
                }
            }
        }
        if (x_count != o_count && x_count != o_count + 1) {
            return false;
        }
        bool x = false;
        bool o = false;
        for (int i = 0; i < board.size(); i++) {
            int row_x = 0;
            int row_o = 0;
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X') {
                    row_x += 1;
                } else if (board[i][j] == 'O') {
                    row_o += 1;
                }
            }
            if (row_x >= 3) {
                x = true;
            }
            if (row_o >= 3) {
                o = true;
            }
        }
        for (int j = 0; j < board[0].size(); j++) {
            int col_x = 0;
            int col_o = 0;
            for (int i = 0; i < board.size(); i++) {
                if (board[i][j] == 'X') {
                    col_x += 1;
                } else if (board[i][j] == 'O') {
                    col_o += 1;
                }
            }
            if (col_x >= 3) {
                x = true;
            }
            if (col_o >= 3) {
                o = true;
            }
        }
        int diag_x = 0;
        int diag_o = 0;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][i] == 'X') {
                diag_x += 1;
            } else if (board[i][i] == 'O') {
                diag_o += 1;
            }
        }
        if (diag_x >= 3) {
            x = true;
        }
        if (diag_o >= 3) {
            o = true;
        }
        int in_diag_x = 0;
        int in_diag_o = 0;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][board.size() - 1 - i] == 'X') {
                in_diag_x += 1;
            } else if (board[i][board.size() - 1 - i] == 'O') {
                in_diag_o += 1;
            }
        }
        if (in_diag_x >= 3) {
            x = true;
        }
        if (in_diag_o >= 3) {
            o = true;
        }
        if (x) {
            return !o && o_count < x_count;
        }
        if (o) {
            return o_count == x_count;
        }
        return true;
    }
};