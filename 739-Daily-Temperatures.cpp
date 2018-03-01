/*
  Daily Temperatures

  Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

  For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

  Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

 */

#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> stk;
    int pos = 0;
    vector<int> res(temperatures.size(), 0);
    while(pos < temperatures.size()) {
        while(!stk.empty() && temperatures[stk.top()] < temperatures[pos]) {
            res[stk.top()] = pos - stk.top();
            stk.pop();
        }
        stk.push(pos);
        pos += 1;
    }
    return res;
}
