#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dichotomy(vector<int>& ordered, int left, int right, int target) {
    if(left > right)
        return false;
    int medium = (left + right) / 2;
    if(target == ordered[medium])
    	return true;
    else if(target < ordered[medium]) {
    	return dichotomy(ordered, left, medium - 1, target);
    }
    else
        return dichotomy(ordered, medium + 1, right, target);
}

bool nextSearch(vector<int>& nums, int left, int right, int target) {
    if(left > right)
        return false;
    int medium = (left + right) / 2;
    int ordered_left, ordered_right, unorder_left, unorder_right;
    if(nums[left] < nums[right])
    	return dichotomy(nums, left, right, target);
    else if(nums[left] == nums[right]) {
    	if(nums[left] == target)
    		return true;
    	else {
    		int tmp = nums[left];
    		while(left <= nums.size() && nums[left] == tmp)
    			left += 1;
    		while(right >= 0 && nums[right] == tmp)
    			right -= 1;
    		return nextSearch(nums, left, right, target);
    	}
    }
    else {
	    if(nums[left] <= nums[medium]) {
	        ordered_left = left;
	        ordered_right = medium;
	        unorder_left = medium + 1;
	        unorder_right = right;
	    }
	    else {
	        ordered_left = medium + 1;
	        ordered_right = right;
	        unorder_left = left;
	        unorder_right = medium;
	    }
	}
    if(target >= nums[ordered_left] && target <= nums[ordered_right])
        return dichotomy(nums, ordered_left, ordered_right, target);
    else
        return nextSearch(nums, unorder_left, unorder_right, target);
}

bool search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	return nextSearch(nums, left, right, target);
}

int main() {
	int n;
	cout << "Please input n: ";
	cin >> n;
	vector<int> nums;
	int val;
	for(int i = 0; i < n; ++i) {
		cin >> val;
		nums.push_back(val);
	}
	int target;
	cout << "Please input target: ";
	cin >> target;
	if(search(nums, target))
		cout << target << " Exist in nums" << endl;
	else
		cout << target << " not Exist in nums" << endl;
	return 0;
}
