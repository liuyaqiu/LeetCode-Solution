#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void leftToRight(vector<int>& height, vector<int>& res) {
    stack<int> pos;
    int cur = 0;
    while(cur < height.size()) {
        if(pos.empty() || height[cur] >= height[pos.top()])
            pos.push(cur);
        else {
            while(!pos.empty() && height[cur] < height[pos.top()]) {
                int tmp = pos.top();
                res[tmp] += (cur - tmp - 1) * height[tmp]; 
                pos.pop();
            }
            pos.push(cur);
        }
        cur += 1;
    }
    while(!pos.empty()) {
        int tmp = pos.top();
        res[tmp] += (cur - tmp - 1) * height[tmp];
        pos.pop();
    }
}

void rightToleft(vector<int>& height, vector<int>& res) {
    stack<int> pos;
    int cur = height.size() - 1;
    while(cur >= 0) {
        if(pos.empty() || height[cur] >= height[pos.top()])
            pos.push(cur);
        else {
            while(!pos.empty() && height[cur] < height[pos.top()]) {
                int tmp = pos.top();
                res[tmp] += (tmp - cur - 1) * height[tmp];
                pos.pop();
            }
            pos.push(cur);
        }
        cur -= 1;
    }
    while(!pos.empty()) {
        int tmp = pos.top();
        res[tmp] += (tmp - cur - 1) * height[tmp];
        pos.pop();
    }
}

void print(vector<int>& res) {
    for(auto iter = res.begin(); iter != res.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int largestRectangleArea(vector<int>& heights) {
    vector<int> res(heights);
    print(res);
    leftToRight(heights, res);
    print(res);
    rightToleft(heights, res);
    print(res);
    int max = 0;
    for(auto iter = res.begin(); iter != res.end(); ++iter)
        if(*iter > max)
            max = *iter;
    return max;
}

int main() {
    int n;
    cout << "Please input n: ";
    cin >> n;
    vector<int> heights;
    int val;
    for(int i = 0; i < n; ++i) {
        cin >> val;
        heights.push_back(val);
    }
    cout << "The largeest rectangle area :" << largestRectangleArea(heights) << endl;
}
