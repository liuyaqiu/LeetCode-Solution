#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    if(nums.empty())
        return 0;
    int dup = 0;
    int len = nums.size();
    for(int i = 0; i < len; i += 1) {
        int pos = i - dup;
        if(nums[pos] == val) {
            nums.erase(nums.begin() + pos);
            dup += 1;
        }
    }
    return nums.size();
}
