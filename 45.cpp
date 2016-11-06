#include <iostream>
#include <string>
#include <vector>

using namespace std;

int jump1(vector<int>& nums) {
    vector<vector<int>> pre_point(nums.size());
    for(int i = 0; i < nums.size(); i += 1) {
        for(int j = 1; j <= nums[i]; j += 1) {
        	if(i + j < nums.size())
            	pre_point[i + j].push_back(i);
        }
    }
    vector<int> res(nums.size(), 0);
    for(int i = 1; i < res.size(); i += 1) {
        int min = res[pre_point[i][0]];
        for(int j = 1; j < pre_point[i].size(); j += 1) {
            if(res[pre_point[i][j]] < min)
                min = res[pre_point[i][j]];
        }
        res[i] = min + 1;
    }
    return res.back();
}

vector<int> jump(vector<int>& nums) {
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
    return res;
}

void print(vector<int> res) {
	for(auto iter = res.begin(); iter != res.end(); iter += 1) {
		cout << *iter << " ";
	}
	cout << endl;
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
    vector<int> res = jump(nums);
    print(res);
	cout << "The res is " << res.back() << endl;
	return 0;
}
