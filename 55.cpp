#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<int> res) {
	for(auto iter = res.begin(); iter != res.end(); iter += 1) {
		cout << *iter << " ";
	}
	cout << endl;
}

bool canJump(vector<int>& nums) {
    vector<int> res(nums.size(), 0);
    int max = 0;
    for(int i = 0; i < nums.size(); i += 1) {
        int tmp = nums[i];
        for(int j = max + 1; j <= i + tmp && j < nums.size(); j += 1) {
            if(j > i && (res[j] == 0 || res[i] + 1 < res[j]))
                res[j] = res[i] + 1;
        }
        if(i + tmp > max)
        	max = i + tmp;
    }
    for(auto iter = res.begin() + 1; iter != res.end(); ++iter) {
    	if(*iter == 0)
    		return false;
    }
    return true;
}

int main() {
	int n;
	cout << "Please input the number of nums: ";
	cin >> n;
	vector<int> nums;
	int val;
	while(n > 0) {
		cin >> val;
		nums.push_back(val);
		n -= 1;
	}
	print(nums);
    string res = canJump(nums) ? "Yes" : "No";
	cout << "The res is " << res << endl;
	return 0;
}