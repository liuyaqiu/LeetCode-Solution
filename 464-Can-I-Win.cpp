#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool search(map<int, bool>& dp, int maxChooseableInteger, int desiredTotal, int state, int total) {
    for(int i = maxChooseableInteger; i >= 1; i--) {
        if(!(state & (1 << (i - 1)))) {
            if(total + i >= desiredTotal) {
                dp[state] = true;
                return true;
            }
            break;		//当前选中的为最大可用的数，没有必要去查找更新的值
        }
    }
    //当前无法直接取胜，需要观察对手的取胜情况
    for(int i = 1; i <= maxChooseableInteger; i++) {
        if(!(state & (1 << (i - 1)))) {
            int nstate = state | (1 << (i - 1));    //我方选中i后对方的胜负策略
            if(dp.find(nstate) == dp.end())
                dp[nstate] = search(dp, maxChooseableInteger, desiredTotal, nstate, total + i);
            if(!dp[nstate]) {   //对方不能获胜，即己方获胜
                dp[state] = true;
                return true;
            }
        }
    }
    //在我方所有的可选策略中，均没有发现能使对方必败的选择，所以不存在必胜策略
    dp[state] = false;
    return false;
}

bool canIWin(int maxChooseableInteger, int desiredTotal) {
    if(maxChooseableInteger >= desiredTotal)
        return true;
    if(maxChooseableInteger* (1 + maxChooseableInteger) < 2 * desiredTotal)
        return false;
    map<int, bool> dp;
    return search(dp, maxChooseableInteger, desiredTotal, 0, 0);
}

