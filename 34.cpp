#include <iostream>
#include <string>
#include <vector>

using namespace std;

int leftSearch(vector<int>& nums, int target, int left, int pos) {
	int right = pos;
    if(left > right)
        return -1;
    if(nums[left] == target)
        return left;
    int medium = (left + right) / 2;
    if(nums[medium] == target) {
    	int tmp = leftSearch(nums, target, left, medium - 1);
    	if(tmp < 0)
    		return medium;
    	else
    		return tmp;
    }
    else
        return leftSearch(nums, target, medium + 1, right);
}

int rightSearch(vector<int>& nums, int target, int pos, int right) {
	int left = pos;
    if(left > right)
    	return -1;
    if(nums[right] == target)
        return right;
    int medium = (left + right) / 2;
    if(nums[medium] == target) {
    	int tmp = rightSearch(nums, target, medium + 1, right);
        if(tmp < 0)
        	return medium;
        else
        	return tmp;
    }
    else
        return rightSearch(nums, target, left, medium - 1);
}

void search(vector<int>& nums, int target, int& left, int& right) {
    if(left > right) {
        left = -1;
        right = -1;
        return;
    }
    int medium = (left + right) / 2;
    if(nums[medium] == target) {
        left = leftSearch(nums, target, left, medium - 1);
        right = rightSearch(nums, target, medium + 1, right);
        if(left == -1)
            left = medium;
        if(right == -1)
            right = medium;
    }
    else if(nums[medium] < target) {
        left = medium + 1;
        search(nums, target, left, right);
    }
    else {
        right = medium - 1;
        search(nums, target, left, right);
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    search(nums, target, left, right);
    vector<int> res;
    res.push_back(left);
    res.push_back(right);
    return res;
}

void print(vector<int>& vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
	//vector<int> vec = {0,0,1,1,2,2,2,2,3,3,4,4,4,5,6,6,6,7,8,8};
	//int target = 4;
	vector<int> vec = {1};
	int target = 0;
    print(vec);
    vector<int> res = searchRange(vec, target);
    print(res);
    return 0;
}
