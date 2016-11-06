#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

void print(vector<int>& nums) {
	for(auto iter = nums.begin(); iter != nums.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

vector<int> getFac(int n) {
	vector<int> fac;
	int cur = 1;
	fac.push_back(1);
	for(int i = 1; i <= n; ++i) {
		cur = cur * i;
		fac.push_back(cur);
	}
	return fac;
}

vector<int> getNum(int n) {
	vector<int> nums;
	for(int i = 0; i <= n; ++i)
		nums.push_back(i);
	return nums;
}

int factor(int n, vector<int>& fac) {
	return fac[n];
}

int remain(int n, int k, vector<int>& fac) {
	return k - factor(n - 1, fac) * (ceil(float(k) / factor(n - 1, fac)) - 1);
}

int cur(int n, int k, vector<int>& fac) {
    return ceil(float(k) / factor(n - 1, fac));
}

string getPermutation(int n, int k) {
	vector<int> fac = getFac(n);
    vector<int> nums = getNum(n);
    string s;
    while(n > 0) {
        int pos = cur(n, k, fac);
        s += nums[pos] + '0';
        nums.erase(nums.begin() + pos);
        k = remain(n, k, fac);
        n -= 1;
    }
    return s;
}

int main() {
    int n, k;
    cout << "Please input the n and k: ";
    cin >> n >> k;
    cout << getRes(n, k) << endl;
    return 0;
}
