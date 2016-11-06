#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    int cur = 1;
    vector<int> tmp;
    tmp.push_back(cur);
    while(true) {
        cur = tmp.back();
        if(cur > n) {
            tmp.pop_back();
            if(tmp.empty())
                break;
            else
                tmp.back() += 1;
        }
        else {
            if(tmp.size() < k)
                tmp.push_back(cur + 1);
            else {
                res.push_back(tmp);
                tmp.back() += 1;
            }
        }
    }
    return res;
}

void print(vector<int> nums) {
    for(auto iter = nums.begin(); iter != nums.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int main() {
    int n, k;
    printf("Please input the n and k: ");
    scanf("%d%d", &n, &k);
    vector<vector<int>> res = combine(n, k);
    for(auto iter = res.begin(); iter != res.end(); ++iter)
        print(*iter);
    cout << res.size() << endl;
    return 0;
}
