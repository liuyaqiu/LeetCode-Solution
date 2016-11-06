#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numTrees(int n) {
    vector<int> res(n + 1, 0);
    res[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < n; ++j) {
            res[i] += res[j] * res[i - 1 - j];
        }
    }
    return res.back();
}
