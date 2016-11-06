#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& array) {
    int maxSum = 0, thisSum = 0;
    int maxItem = array.front();
    bool non_posi = true;
    for(auto iter = array.begin(); iter != array.end(); ++iter) {
    	if(*iter > maxItem)
    		maxItem = *iter;
    	if(*iter > 0)
    		non_posi = false;
        thisSum += *iter;
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }
    if(non_posi)
    	return maxItem;
    else
    	return maxSum;
}

void print(vector<int>& nums) {
	for(auto iter = nums.begin(); iter != nums.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

int main() {
	int n;
	cout << "Please input the number of array: ";
	cin >> n;
	int val;
	vector<int> array;
	while(n > 0) {
		cin >> val;
		array.push_back(val);
		n -= 1;
	}
	int res = maxSubArray(array);
	cout << "The res is: " << res << endl;
}
