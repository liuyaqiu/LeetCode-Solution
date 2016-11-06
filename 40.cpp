#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print(vector<int> res) {
	for(auto iter = res.begin(); iter != res.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

vector<int> clearCandidates(vector<int>& candidates) {
    vector<int> tmp_can;
    vector<int> times;
    if(candidates.empty())
        return times;
    int val = candidates.front();
    tmp_can.push_back(val);
    times.push_back(1);
    for(auto iter = candidates.begin() + 1; iter != candidates.end(); ++iter) {
        if(*iter == val)
            times.back() += 1;
        else {
            val = *iter;
            tmp_can.push_back(val);
            times.push_back(1);
        }
    }
    candidates = tmp_can;
    return times;
}

vector<int> curCombination(vector<int>& candidates, vector<int>& times) {
    vector<int> res;
    for(int i = 0; i < times.size(); i += 1) {
        int cnt = times[i];
        while(cnt > 0) {
            res.push_back(candidates[i]);
            cnt -= 1;
        }
    }
    return res;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> times(candidates.size(), 0);
    vector<int> maxCandidates = clearCandidates(candidates);
    if(candidates.empty())
        return res;
    int pos = 0;
    while(true) {
        if(times[pos] > maxCandidates[pos]) {
                target += candidates[pos] * times[pos];
                times[pos] = 0;
                pos -= 1;
                if(pos < 0)
                    break;
                times[pos] += 1;
                target -= candidates[pos];
        }
        else {
            if(target <= 0) {
                if(target == 0)
                    res.push_back(curCombination(candidates, times));
                target += candidates[pos] * times[pos];
                times[pos] = 0;
                pos -= 1;
                if(pos < 0)
                    break;
                times[pos] += 1;
                target -= candidates[pos];
                
            }
            else {
                while(pos + 1 < candidates.size() && candidates[pos + 1] <= target)
                    pos += 1;
                times[pos] += 1;
                target -= candidates[pos];
            }
        }
    }
    return res;
}

int main() {
	vector<int> nums;
    cout << "Please input the number of nums: ";
    int n;
    cin >> n;
    cout << "Input the nums: ";
    while(n > 0) {
        int val;
        cin >> val;
        nums.push_back(val);
        n -= 1;
    }
    int target;
    cout << "Input the target: ";
    cin >> target;
    cout << "The nums is: " << endl;
    print(nums);
	vector<vector<int>> res = combinationSum(nums, target);
    cout << "There are " << res.size() << " solutions: "<<endl;
	for(auto iter = res.begin(); iter != res.end(); ++iter)
		print(*iter);
	return 0;
}
