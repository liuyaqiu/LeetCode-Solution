/*
Remove Boxes

Given several boxes with different colors represented by different positive numbers. 
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.

Example 1:
Input:

[1, 3, 2, 2, 2, 3, 4, 3, 1]
Output:
23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
Note: The number of boxes n would not exceed 100.

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int solve(vector<int>& color, vector<int>& length, vector<vector<vector<int>>>& dp, int start, int end, int cnt) {
    if(start > end)
        return 0;
    if(dp[start][end][cnt] != 0)
        return dp[start][end][cnt];
    int points = solve(color, length, dp, start, end - 1, 0) + pow(length[end] + cnt, 2);
    for(int i = start; i < end; i++) {
        if(color[i] == color[end])
            points = max(points, solve(color, length, dp, start, i, length[end] + cnt) + solve(color, length, dp, i + 1, end - 1, 0));
    }
    dp[start][end][cnt] = points;
    return points;
}

int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    vector<int> length, color;
    for(auto box: boxes) {
        if(!color.empty() && box == color.back())
            length.back() += 1;
        else {
            color.push_back(box);
            length.push_back(1);
        }
    }
    int m = color.size();
    map<int, int> sums;
    for(int i = 0; i < color.size(); i++) {
        if(sums.find(color[i]) != sums.end()) {
            sums[color[i]] += length[i];
        }
        else
            sums[color[i]] = length[i];
    }
    int t = 0;
    for(auto item: sums) {
        t = max(t, item.second);
    }
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(m, vector<int>(t, 0)));
    return solve(color, length, dp, 0, m - 1, 0);
}

int main() {
    vector<int> boxes;
    int val;
    while(cin >> val) {
        boxes.push_back(val);
    }
    int res = removeBoxes(boxes);
    cout << res << endl;
    return 0;
}
