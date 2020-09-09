/*
 * String to Integer
 *
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 *
 *  
 *
 *  Requirements for atoi:
 *
 *  The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 *
 *  The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 *
 *  If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 *
 *  If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 *
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int myAtoi(string s) {
	int start = 0;
	while(s[start] == ' ')
		start++;
	bool isNega = false;
	if(s[start] == '-') {
		start++;
		isNega = true;
	}
	else {
		if(s[start] == '+')
		start++;
	}
	cout<<isNega<<endl;
	if(s[start] - '0' < 0 || s[start] - '0' > 9)
		return 0;
	while(s[start] == '0')
		start++;
	int i = 0;
	while(s[start + i] - '0' >= 0 && s[start + i] - '0' <= 9)
		i++;
	long long int res = 0;
	int nega = 1;
	if(isNega)
		nega = -1;
	for(int j = 0; j < i; j++) {
		res += nega * (s[start + i - 1 - j] - '0') * pow(10, j);
		if((i > 10 && !isNega) || res >= pow(2, 31))
			return int(pow(2, 31) - 1);
		if((i > 10 && isNega) || res < (-1) * pow(2, 31))
			return int((-1) * pow(2, 31));
	}
	return res;
}

int main() {
	string s;
	cout<<"Please input the string: ";
	cin>>s;
	cout<<"It is the integer: "<<myAtoi(s)<<endl;
	return 0;
}
