#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
    vector<bool> judge(n, true);
    for(int i = 2; i < n; i++) {
        if(judge[i]) {
            for(int j = 2 * i; j < n; j += i)
                judge[j] = false;
        }
    }
    int res = 0;
    for(int i = 2; i < n; i++) {
        if(judge[i])
            res += 1;
    }
    return res;
}
