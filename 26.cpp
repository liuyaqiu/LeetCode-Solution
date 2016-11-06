#include <iosteram>
#include <string>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int dup = 0;
    int len = nums.size();
    for(int i = 1; i < len; i += 1) {
    	int pos = i - dup;
    	if(nums[pos] == nums[pos - 1]) {
    	    nums.erase(nums.begin() + pos);
    		dup += 1;
    	}
    }
    return nums.size();
}
