#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
 * Guess Number Higher or Lower II
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
 *
 * However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
 *
 * Example:
 *
 * n = 10, I pick 8.
 *
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 *
 * Game over. 8 is the number I picked.
 *
 * You end up paying $5 + $7 + $9 = [1.
 * Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
 *
 *
 */

#define inf numeric_limits<int>::max()

int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int delta = 1; delta <= n - 1; delta++) {
        for(int start = 1; start <= n - delta; start++) {
            int end = start + delta;
            dp[start][end] = inf;
            for(int k = start; k < end; k++)
                dp[start][end] = min(dp[start][end], k + max(dp[start][k - 1], dp[k + 1][end]));
        }
    }
    return dp[1][n];
}

int main() {
    int n;
    cin >> n;
    int res = getMoneyAmount(n);
    cout << res << endl;
    return 0;
}
