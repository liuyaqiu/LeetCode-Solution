#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
 * Expression Add Operators
 *
 * Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
 *
 * Examples: 
 * "123", 6 -> ["1+2+3", "1*2*3"] 
 * "232", 8 -> ["2*3+2", "2+3*2"]
 * "105", 5 -> ["1*0+5","10-5"]
 * "00", 0 -> ["0+0", "0-0", "0*0"]
 * "3456237490", 9191 -> []
 *
 *
 */

void helper(string num, int start, int target, long curSum, long preNum, string curResult, vector<string>& res) {
    int n = num.length();
    if(start == n && curSum == target) {
        res.push_back(curResult);
        return;
    }
    if(start == n)
        return;
    for(int i = start + 1; i <= n; i++) {
        string curStr = num.substr(start, i - start);
        if(curStr.length() > 1 && curStr[0] == '0')
            break;
        long curNum;
        stringstream ss;
        ss << curStr;
        ss >> curNum;
        if(curResult.empty()) {
            helper(num, i, target, curNum, curNum, curStr, res);
        }
        else {
            helper(num, i, target, curSum - preNum + preNum * curNum, preNum * curNum, curResult + "*" + curStr, res);
            helper(num, i, target, curSum + curNum, curNum, curResult + "+" + curStr, res);
            helper(num, i, target, curSum - curNum, -curNum, curResult + "-" + curStr, res);
        }
    }
} 

vector<string> addOperators(string num, int target) {
    vector<string> res;
    if(num.empty())
        return res;
    helper(num, 0, target, 0, 0, "", res);
    return res;
}

void print(vector<string>& res) {
    for(auto iter = res.begin(); iter != res.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

int main() {
    string num;
    int target;
    cin >> num >> target;
    vector<string> res = addOperators(num, target);
    print(res);
    return 0;
}
