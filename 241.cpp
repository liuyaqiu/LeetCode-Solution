#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

vector<int> merge(vector<int>& left, vector<int>& right, char op) {
    vector<int> res;
    for(auto iter1 = left.begin(); iter1 != left.end(); iter1++) {
        for(auto iter2 = right.begin(); iter2 != right.end(); iter2++) {
            int tmp = 0;
            if(op == '*')
                tmp = *iter1 * *iter2;
            else if(op == '+')
                tmp = *iter1 + *iter2;
            else if(op == '-')
                tmp = *iter1 - *iter2;
            res.push_back(tmp);
        }
    }
    return res;
}

bool isDigit(char c) {
    return c - '0' >= 0 && c - '0' < 10;
}

vector<int> diffWaysToCompute(string input) {
    int n = input.length();
    vector<int> res;
    for(int i = 1; i < n - 1; i++) {
        if(!isDigit(input[i])) {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1, n - i - 1));
            vector<int> tmp = merge(left, right, input[i]);
            for(auto iter = tmp.begin(); iter != tmp.end(); iter++)
                res.push_back(*iter);
        }
    }
    if(res.empty()) {
        stringstream ss;
        ss << input;
        int tmp;
        ss >> tmp;
        res.push_back(tmp);
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    vector<int> res = diffWaysToCompute(s);
    print(res);
    return 0;
}
