/*
 * Generate Parentheses
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getAllSequence(int cur, int size, int stk, string seq, vector<string>& res) {
    if(cur == size) {
        seq.append(stk, ')');
        res.push_back(seq);
    } 
    else {
        getAllSequence(cur + 1, size, stk + 1, seq + '(', res);
        if(stk > 0)
            getAllSequence(cur, size, stk - 1, seq + ')', res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    getAllSequence(0, n, 0, "", res);
    return res;
}

void print(vector<string> res) {
    for(auto iter = res.begin(); iter != res.end(); ++iter) {
        cout << *iter << endl;
    }
}

int main() {
    int n;
    cout << "Please input the num: ";
    cin >> n;
    vector<string> res = generateParenthesis(n);
    cout << "There are " << res.size() << " solutions: " << endl;
    print(res);
    return 0;
}
