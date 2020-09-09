/*
 * Palindrome Number
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int x) {
	int length = 1;
	if(x < 0)
		return false;
	int y = x;
	while(y > 9) {
		length++;
		y = y / 10;
	}
	int top = 0;
	int tail = 0;
	while(length > 1) {
		top = x / pow(10, length -1);
		tail = x % 10;
		if(top != tail)
			return false;
		else {
			x = (x % int(pow(10, length - 1))) / 10;
			length -= 2;
		}
	}
	return true;
}

int main() {
	int x;
	cout<<"Please input the num: ";
	cin>>x;
	cout<<isPalindrome(x)<<endl;
	return 0;
}
