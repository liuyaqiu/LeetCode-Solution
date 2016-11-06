#include <iostream>
#include <vector>
#include <string>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
	if(nums.empty())
		return 1;
	nums.push_back(0);
    int len = nums.size();
    for(int i = 0; i < len; i += 1) {
        while(nums[i] != i) {   //不断查找，nums[i]位置最终要么放置i，要么放置一个超出范围的数
            int tmp = nums[i];
            if(tmp >= 0 && tmp < len && nums[i] != nums[tmp])
                swap(nums[i], nums[tmp]);   //对于这一步，tmp位置被更新为tmp，位置得到确认，下次不会再发生调整，显然，对于n个数，由于每次有一个数位置确认，因此最多发生n次调整
            else
                break;
        }
    }
    //经过至多n次的调整之后，数组中的每个位置i，或者存储了元素i，或者存储了一个超出范围的元素，而且数组中的重复元素均被调整到数组尾部
    //显然，对数组进行遍历，从i = 1开始，首次出现失序的位置，即为缺失元素，若所有元素均有序，那么说明n个元素恰好包含所有1到n，结果为n + 1
    for(int i = 1; i < len; i += 1) {
        if(nums[i] != i)
            return i;
    }
    return nums.back() + 1;
}

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Input the number of nums: ";
    cin >> n;
    cout << "Input the nums: ";
    int val;
    vector<int> nums;
    while(n > 0) {
        cin >> val;
        nums.push_back(val);
        n -= 1;
    }
    print(nums);
    int res = firstMissingPositive(nums);
    print(nums);
    cout << "The first missing positive is: " << res << endl;
    return 0;
}
