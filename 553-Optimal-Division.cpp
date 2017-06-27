#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

template<typename T> void print(vector<vector<T>>& nums) {
    for(auto row: nums) {
        for(auto item: row)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}

#define inf numeric_limits<double>::max()

void solve(vector<int>& nums, int start, int end, vector<vector<double>>& maxi, vector<vector<double>>& mini, vector<vector<string>>& smax, vector<vector<string>>& smin) {
    if(maxi[start][end] != 0)
        return;
    if(end <= start)
        return;
    else if(end - start == 1) {
        maxi[start][end] = nums[start];
        mini[start][end] = nums[start];
        smax[start][end] = to_string(nums[start]);
        smin[start][end] = to_string(nums[start]);
    }
    else {
        int max_index = -1;
        int min_index = -1;
        for(int i = start + 1; i < end; i++) {
            solve(nums, start, i, maxi, mini, smax, smin);
            solve(nums, i, end, maxi, mini, smax, smin);
            double tmp_max = maxi[start][i]/ mini[i][end];
            double tmp_min = mini[start][i]/ maxi[i][end];
            if(tmp_max > maxi[start][end]) {
                max_index = i;
                maxi[start][end] = tmp_max;
            }
            if(tmp_min < mini[start][end]) {
                min_index = i;
                mini[start][end] = tmp_min;
            }
        }
        if(max_index == end - 1) {
            smax[start][end] = smax[start][max_index] + "/" + smin[max_index][end];
        }
        else {
            smax[start][end] = smax[start][max_index] + "/" + "(" + smin[max_index][end] + ")";
        }
        if(min_index == end - 1) {
            smin[start][end] = smin[start][min_index] + "/" + smax[min_index][end];
        }
        else {
            smin[start][end] = smin[start][min_index] + "/" + "(" + smax[min_index][end] + ")";
        }
    }
}

string optimalDivision(vector<int>& nums) {
    int n = nums.size();
    vector<vector<double>> maxi(n, vector<double>(n + 1, 0));
    vector<vector<double>> mini(n, vector<double>(n + 1, inf));
    vector<vector<string>> smax(n, vector<string>(n + 1, ""));
    vector<vector<string>> smin(n, vector<string>(n + 1, ""));
    solve(nums, 0, n, maxi, mini, smax, smin);
    return smax[0][n];
}

int main() {
    vector<int> nums;
    int val;
    while(cin >> val) {
        nums.push_back(val);
    }
    string res = optimalDivision(nums);
    cout << res << endl;
    return 0;
}
