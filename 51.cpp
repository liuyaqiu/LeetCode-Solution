#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <set>
#include <string>

using namespace std;

int erasePoint(vector<set<int>>& judge, vector<int>& queens) {
    int row = queens.size() - 1;
    int col = queens.back();
    queens.pop_back();
    vector<int> cur = {row, col, row - col, row + col};
    for(int i = 0; i < cur.size(); i += 1)
        judge[i].erase(cur[i]);
    return col;
}

bool nextQueen(vector<int>& queens, vector<set<int>>& judge, int start, int len) {
    int row = queens.size();
    for(int col = start; col < len; col += 1) {
        vector<int> cur = {row, col, row - col, row + col};
        bool use = true;
        for(int i = 0; i < cur.size(); i += 1) {
            if(judge[i].find(cur[i]) != judge[i].end()) {
                use = false;
                break;
            }
        }
        if(use) {
            for(int i = 0; i < cur.size(); i += 1)
                judge[i].insert(cur[i]);
            queens.push_back(col);
            return true;
        }
    }
    return false;
}

vector<string> getSolution(vector<int>& queens, int len) {
    vector<string> res;
    for(auto iter = queens.begin(); iter != queens.end(); ++iter) {
        string line(len, '.');
        line[*iter] = 'Q';
        res.push_back(line);
    }
    return res;
}

vector<vector<string>> solveQueens(int n) {
    vector<set<int>> judge(4);
    vector<int> queens;
    vector<vector<string>> res;
    int col = 0;
    while(true) {
        if(queens.size() >= n) {
            res.push_back(getSolution(queens, n));
            col = erasePoint(judge, queens) + 1;
        }
        else {
            if(!nextQueen(queens, judge, col, n)) {
                if(queens.empty())
                    break;
                col = erasePoint(judge, queens) + 1;
            }
            else {
                col = 0;
            }
        }
    }
    return res;
}

void print(vector<string> vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << endl;
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Please input the num: ";
    cin >> n;
    vector<vector<string>> res = solveQueens(n);
    cout << res.size() << " solutions: " << endl;
    for(int i = 0; i < res.size(); i += 1) {
        cout << i << " solution: " << endl;
        print(res[i]);
    }
    return 0;
}
