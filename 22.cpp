#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getAllSequence(int cur, int size, int stk, string& seq, vector<string>& res) {
    if(cur == size) {
        seq.append(stk, ')');
        res.push_back(seq);
    } 
    else {
        stk += 1;
        string tmp = seq;
        seq += '(';
        getAllSequence(cur + 1, size, stk, seq, res);
        stk -= 1;
        seq = tmp;
        if(stk > 0) {
            string tmp = seq;
            seq += ')';
            stk -= 1;
            getAllSequence(cur, size, stk, seq, res);
            seq = tmp;
            stk += 1;
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string seq(""); 
    getAllSequence(0, n, 0, seq, res);
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
