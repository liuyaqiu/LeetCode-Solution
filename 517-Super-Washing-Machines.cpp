#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int findMinMoves(vector<int>& machines) {
    int sum = accumulate(machines.begin(), machines.end(), 0);
    if(sum % machines.size() != 0)
        return -1;
    int avg = sum / machines.size();
    int res = 0, total = 0;
    for(auto m: machines) {
        total += m - avg;
        res = max(res, max(abs(total), m - avg));
    }
    return res;
}

