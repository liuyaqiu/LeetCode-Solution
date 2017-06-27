#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> a) {
    vector<int> res(a.size() + 1, 0);
    for(int i = 0; i < res.size(); i++) {
        if(i == 0)
            res[i] = a[0];
        else if(i == res.size() - 1)
            res[i] = a[i - 1];
        else
            res[i] = a[i] + a[i - 1];
    }
    return res;
}

vector<vector<int>> generate(int n) {
    vector<int> a = {1};
    vector<vector<int>> res;
    while(a.size() <= n) {
        res.push_back(a);
        a = merge(a);
    }
    return res;
}
