#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<int>& array) {
    for(auto iter = array.begin(); iter != array.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

void sortColors(vector<int>& nums) {
    int red = 0, white = 0, blue = 0;
    for(auto iter = nums.begin(); iter != nums.end(); ++iter) {
        if(*iter == 0)
            red += 1;
        else if(*iter == 1)
            white += 1;
        else if(*iter == 2)
            blue += 1;
    }
    for(auto iter = nums.begin(); iter != nums.end(); ++iter) {
        if(red > 0) {
            *iter = 0;
            red -= 1;
        }
        else if(white > 0) {
            *iter = 1;
            white -= 1;
        }
        else if(blue > 0) {
            *iter = 2;
            blue -= 1;
        }
    }
}

void sortColors2(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    while(start < nums.size() && nums[start] == 0)
        start += 1;
    while(end >= 0 && nums[end] == 2)
        end -= 1;
    int pos = start;
    while(pos <= end) {
        if(nums[pos] == 0) {
        	if(pos > start) {
        		swap(nums[pos], nums[start]);
            	start += 1;
        	}
        	else
        		pos += 1;
        }
        else if(nums[pos] == 1) {
            pos += 1;
        }
        else if(nums[pos] == 2) {
        	if(pos < end) {
	            swap(nums[pos], nums[end]);
	            end -= 1;
        	}
        	else
            	pos += 1;
        }
    }
}

int main() {
	int n;
	cout << "Input the number: ";
	cin >> n;
	int val;
	vector<int> array;
	while(n > 0) {
		cin >> val;
		array.push_back(val);
        n -= 1;
	}
    print(array);
    sortColors2(array);
    print(array);
    return 0;
}

