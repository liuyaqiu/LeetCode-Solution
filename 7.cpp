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