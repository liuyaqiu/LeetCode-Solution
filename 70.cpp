#include <iostream>
#include <string>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if(n <= 1)
        return 1;
    vector<int> res(n + 1, 0);
    res[0] = 1;
    res[1] = 1;
    for(int i = 2; i < n + 1; ++i) {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res.back();
}

int main() {
    int n;
    cout << "Please input n: ";
    cin >> n;
    cout << "The result is: " << climbStairs(n) << endl;
}
