#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, bool> mytuple;

mytuple next(mytuple cur, int m, int n) {
    int x = get<0>(cur), y = get<1>(cur);
    bool dir = get<2>(cur);
    if(dir) {
        //当前方向为向右上方移动
        if(x == 0) {
            if(y + 1 < n)
                return mytuple(0, y + 1, false);
            else
                return mytuple(1, y, false);
        }
        else {
            if(y + 1 < n)
                return mytuple(x - 1, y + 1, true);
            else
                return mytuple(x + 1, y, false);
        }
    }
    else {
        if(y == 0) {
            if(x + 1 < m)
                return mytuple(x + 1, 0, true);
            else
                return mytuple(x, 1, true);
        }
        else {
            if(x + 1 < m)
                return mytuple(x + 1, y - 1, false);
            else
                return mytuple(x, y + 1, true);
        }
    }
}

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    mytuple cur(0, 0, true);
    vector<int> res;
    if(matrix.empty())
        return res;
    int m = matrix.size();
    int n = matrix[0].size();
    while(get<0>(cur) < m && get<1>(cur) < n) {
        int i = get<0>(cur), j = get<1>(cur);
        res.push_back(matrix[i][j]);
        cur = next(cur, m, n);
    }
    return res;
}
