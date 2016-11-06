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