/*
 * Permutations II
 *
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void print(vector<int> res) {
	for(auto iter = res.begin(); iter != res.end(); iter += 1) {
		cout << *iter << " ";
	}
	cout << endl;
}

vector<vector<int>> permute(vector<int>& nums) {
	sort(nums.begin(), nums.end());
    int pos = 0;
    int len = nums.size();
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> judge(len, true);
    int pre_pos;
    bool is_pop = false;
    stack<int> all_pos;
    while(true) {
        if(cur.size() < len) {
            while(pos != pre_pos && !judge[pos]) {
                pos = (pos + 1) % len;
            }
            if(is_pop) {
                if(pos <= pre_pos) {
                    if(cur.empty())
                        break;
                    cur.pop_back();
                    pre_pos = all_pos.top();
                    all_pos.pop();
                    judge[pre_pos] = true;
                    pos = (pre_pos + 1) % len;
                    is_pop = true;
                }
                else {
                	if(nums[pos] == nums[pre_pos]) {
                		pos = (pos + 1) % len;
                	}
                	else {
	                    cur.push_back(nums[pos]);
	                    all_pos.push(pos);
	                    judge[pos] = false;
	                    pos = (pos + 1) % len;
	                    is_pop = false;
                	}
                }
            }
            else {
                pos = 0;
                while(!judge[pos])
                    pos += 1;
                cur.push_back(nums[pos]);
                all_pos.push(pos);
                judge[pos] = false;
                pos = (pos + 1) % len;
                is_pop = false;
            }
        }
        else {
            res.push_back(cur);
            cur.pop_back();
            pre_pos = all_pos.top();
            all_pos.pop();
            judge[pre_pos] = true;
            pos = (pre_pos + 1) % len;
            is_pop = true;
        }
    }
    return res;
}


int main() {
    int n;
    cout << "Please input the number of nums: ";
    cin >> n;
    int val;
    vector<int> nums;
    while(n > 0) {
        cin >> val;
        nums.push_back(val);
        n -= 1;
    }
    cout << "The nums: ";
    print(nums);
    vector<vector<int>> res = permute(nums);
    cout << "The res: " << endl;
    for(auto iter = res.begin(); iter != res.end(); iter += 1)
        print(*iter);
    return 0;
}
