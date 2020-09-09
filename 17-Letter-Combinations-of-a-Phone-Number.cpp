/*
 * Letter Combinations of a Phone Number
 *
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 *
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> merge(vector<string>& pre, vector<string>& cur) {
    vector<string> res;
    for(auto iter1 = pre.begin(); iter1 != pre.end(); ++iter1) {
        for(auto iter2 = cur.begin(); iter2 != cur.end(); ++iter2) {
            res.push_back(*iter1 + *iter2);
        }
    }
    return res;
}

vector<string> letterCombinations(string digits) {
    map<char, vector<string>> digitSet = {
        {'2', {"a", "b", "c"}}, {'3', {"d", "e", "f"}}, {'4', {"g", "h", "i"}}, {'5', {"j", "k", "l"}}, {'6', {"m", "n", "o"}}, {'7', {"p", "q", "r", "s"}}, {'8', {"t", "u", "v"}}, {'9', {"w", "x", "y", "z"}}
    };
    vector<string> res = digitSet[digits[0]];
    for(int i = 1; i < digits.length(); i += 1) {
        res = merge(res, digitSet[digits[i]]);
    }
    return res;
}

void printVector(vector<string> res) {
    for(auto iter = res.begin(); iter != res.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    string digits = "23";
    vector<string> res = letterCombinations(digits);
    printVector(res);
}
