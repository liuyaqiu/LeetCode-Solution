#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getSet(vector<int>& nums, vector<int>& pos) {
    vector<int> set;
    for(int i = 0; i < pos.size(); ++i) {
        if(pos[i] != 0)
            set.push_back(nums[i]);
    }
    return set;
}

vector<vector<int>> subsets(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> res;
    vector<int> pos;
    while(true) {
        if(pos.size() < len) {
            pos.push_back(0);
        }
        else {
            res.push_back(getSet(nums, pos));
            while(!pos.empty() && pos.back() == 1) {
                pos.pop_back();
            }
            if(!pos.empty())
                pos.back() += 1;
            else
                break;
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
    int n;
    printf("Please input the n: ");
    scanf("%d", &n);
    vector<int> nums;
    int val;
    while(n > 0) {
        scanf("%d", &val);
        nums.push_back(val);
        n -= 1;
    }
    print(nums);
    vector<vector<int>> res = subset(nums);
    for(auto iter = res.begin(); iter != res.end(); ++iter)
        print(*iter);
    cout << res.size() << endl;
    return 0;
}
