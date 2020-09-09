class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int N = board.size(), rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if ((board[0][0] + board[i][0] + board[0][j] + board[i][j]) % 2 != 0) {
                    return -1;
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            rowSum += board[0][i];
            colSum += board[i][0];
            rowSwap += board[i][0] == i % 2;
            colSwap += board[0][i] == i % 2;
        }
        if (N % 2 == 0) {
            if (rowSum != N / 2 || colSum != N / 2) {
                return -1;
            }
            colSwap = min(N - colSwap, colSwap);
            rowSwap = min(N - rowSwap, rowSwap);
        } else {
            if ((rowSum != N / 2 && rowSum != N / 2 + 1) || (colSum != N / 2 && colSum != N / 2 + 1)) {
                return -1;
            }
            if (colSwap % 2 != 0) {
                colSwap = N - colSwap;
            }
            if (rowSwap % 2 != 0) {
                rowSwap = N - rowSwap;
            }
        }
        colSwap = colSwap / 2;
        rowSwap = rowSwap / 2;
        return colSwap + rowSwap;
    }
};