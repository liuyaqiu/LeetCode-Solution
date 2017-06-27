#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(vector<int>& array) {
    for(auto item: array)
        cout << item << " ";
    cout << endl;
}

void permutation(int n, vector<int> cur, int& cnt) {
    int index = n + 1;
    if(cur.empty()) {
        cnt++;
        return;
    }
    for(int i = 0; i < cur.size(); i++) {
        int val = cur[i];
        if(val % index == 0 || index % val == 0) {
            vector<int> cur_tmp(cur);
            auto iter = next(cur_tmp.begin(), i);
            cur_tmp.erase(iter);
            permutation(index, cur_tmp, cnt);
        }
    }
}

int countArrangement(int N) {
    vector<int> cur;
    for(int i = 1; i <= N; i++)
        cur.push_back(i);
    int cnt = 0;
    permutation(0, cur, cnt);
    return cnt;
}

int main() {
    int n;
    cin >> n;
    int res = countArrangement(n);
    cout << res << endl;
    return 0;
}
