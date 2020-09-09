/*
 * Longest Palindromic Substring
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example:
 *
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 *  
 *
 *  Example:
 *
 *  Input: "cbbd"
 *
 *  Output: "bb"
 *
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int palinLength(string s, int pos) {
	int m = 1, n = 1;
	if(s[pos] == s[pos + 1]) {
		int down = pos, up = pos +1;
		while(down > 0 && up < s.length() - 1 && s[down - 1] == s[up + 1]) {
			down -= 1;
			up += 1;
		}
		m = up - down + 1;
	}
	if(s[pos - 1] == s[pos + 1]) {
		int down = pos - 1, up = pos + 1;
		while(down > 0 && up < s.length() - 1 && s[down - 1] == s[up + 1]) {
			down -= 1;
			up += 1;
		}
		n = up - down + 1;
	}
	return m > n ? m : n;
}

string subPalin(string s, int pos, int length) {
	if(length % 2 == 0) {
		if(pos == 0)
			return s.substr(0, 2);
		else
			return s.substr(pos - length / 2 + 1, length);
	}
	else {
		if(pos == 1)
			return s.substr(0, 3);
		else
			return s.substr(pos - length / 2, length);
	}
	}

string longestPalindrome(string s) {
	if(s.length() == 1)
		return s;
	vector<int> point;
	int i = 0;
	while(i < s.length() - 1) {
		if(i == 0 && s[i] == s[i + 1])
			point.push_back(i);
		else {
			if(s[i - 1] == s[i + 1])
				point.push_back(i);
			else {
				if(s[i] == s[i + 1])
					point.push_back(i);
		}
		}
		i += 1;
	}
	cout<<point.size()<<endl;
	int res = 1;
	int pos = 1;
	for(int i = 0; i < point.size(); i++) {
		int tmp = palinLength(s, point[i]);
		if(tmp > res) {
			res = tmp;
			pos = point[i];
		}
	}
	cout<<pos<<" "<<res<<endl;
	return subPalin(s, pos, res);
}

int main() {
	string s;
	cout<<"Please input the string: ";
	cin>>s;
	cout<<longestPalindrome(s)<<endl;
}
