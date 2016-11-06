#include <iostream>
#include <string>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int pos = 0;
    int nextPos = 0;
    int res = 0;
    while(pos < nums.size()) {
        while(nextPos < nums.size() && nums[nextPos] == nums[pos])
            nextPos += 1;
        int len = nextPos - pos;
        if(len > 2)
        	len = 2;
        for(int i = 0; i < len; i++) {
        	nums[res + i] = nums[pos];
        }
        res += len;
        pos = nextPos;
    }
    return res;
}

void print(vector<int>& nums) {
	for(auto iter = nums.begin(); iter != nums.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

int main() {
    int n;
    cout << "Please input n: ";
    cin >> n;
    int val;
    vector<int> nums;
    for(int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }
    cout << "The nums is: ";
    print(nums);
    cout << "The res is: " << removeDuplicates(nums) << endl;
    cout << "The nums after removeDuplicates: ";
    print(nums);
    return 0;
}
