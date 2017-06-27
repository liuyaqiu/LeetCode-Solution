#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target, int start, int end) {
    if(start > end)
        return -1;
    int mid = (start + end) / 2;
    if(target == nums[mid])
        return mid;
    else if(target < nums[mid])
        return search(nums, target, start, mid - 1);
    else
        return search(nums, target, mid + 1, end);
}

vector<int> twoSum(vector<int>& numbers, int target) {
    int end = numbers.size() - 1;
    int res = -1;
    int pos = -1;
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] <= target / 2) {
            int tmp = search(numbers, target - numbers[i], i + 1, end);
            if(tmp != -1) {
                res = tmp + 1;
                pos = i + 1;
            }
        }
        else
            break;
    }
    vector<int> result = {pos, res};
    return result;
}

int main() {
    int val;
    vector<int> nums;
    int target;
    cin >> target;
    while(cin >> val) {
        nums.push_back(val);
    }
    vector<int> res = twoSum(nums, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
