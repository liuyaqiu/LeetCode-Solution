#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

/*int posToVal(int pos) {
    int delta = 4 - pos / 4;
    int k = pos % 4;
    vector<int> tmp = {0, 1, 3, 2};
    return tmp[(k + delta) % 4];
}*/

int posToVal(int pos) {
    vector<int> tmp = {0, 1, 3, 2, 2, 3, 1, 0};
    return tmp[pos % 8];
}

int getVal(int pos, int len) {
    int cnt = ceil(len / 2.0);
    int res = 0;
    for(int i = 0; i < cnt; ++i) {
        res += posToVal(pos / pow(4, i)) * pow(4, i);       
    }
    return res;
}

vector<int> grayCode(int n) {
    vector<int> res;
    for(int i = 0; i < pow(2, n); ++i) {
        res.push_back(getVal(i, n));
    }
    return res;
}

void print(vector<int>& res) {
    for(auto iter = res.begin(); iter != res.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Please input n: ";
    cin >> n;
    getVal(4, 3);
    vector<int> gray = grayCode(n);
    print(gray);
    return 0;
}
