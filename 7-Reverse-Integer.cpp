/*
 * Reverse Integer
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 * Input: 123
 * Output:  321
 * Example 2:
 *
 * Input: -123
 * Output: -321
 * Example 3:
 *
 * Input: 120
 * Output: 21
 * Note:
 * Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *
 */

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int reverse(int x) {
	if(x == 0)
		return 0;
	else {
		stack<int> digit;
		bool nega = false;
		if(x < 0) {
			x *= -1;
			nega = true;
		}
		while(x >= 10) {
		digit.push(x % 10);
		x = x / 10;
		}
		digit.push(x);
		int res = 0;
		int i = 0;
		while(! digit.empty()) {
			res = res + digit.top() * pow(10, i);
			i += 1;
			digit.pop();
		}
		if(res < 0)
			return 0;
		if(nega)
			res *= -1;
		return res;
		}
}

int main() {
	int x;
	cout<<"Please input the num: ";
	cin>>x;
	cout<<"This is the reverse num: "<<reverse(x)<<endl;
	return 0;
}
