#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isDigit(char c) {
    int num = c - '0';
    return num >= 0 && num <= 9;
}

string noSpace(string s) {
	int pos1 = 0;
	string res;
	while(pos1 < s.length() && s[pos1] == ' ')
		pos1 += 1;
	if(pos1 == s.length())
		return res;
	else
		res = s.substr(pos1, s.length() - pos1);
	int pos2 = res.length() - 1;
	while(pos2 >= 0 && res[pos2] == ' ')
		pos2 -= 1;
	return res.substr(0, pos2 + 1);
}

bool isInteger(string s) {
	if(s[0] == '+' || s[0] == '-')
		s = s.substr(1, s.length() - 1);
	if(s.empty())
		return false;
    for(int i = 0; i < s.length(); ++i) {
        if(!isDigit(s[i]))
            return false;
    }
    return true;
}

bool isFloat(string s) {
	if(s[0] == '+' || s[0] == '-')
		s = s.substr(1, s.length() - 1);
	if(s == "." || s.empty())
		return false;
    int pos_point = -1;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '.') {
            if(pos_point == -1)
                pos_point = i;
            else
                return false;
        }
    }
    if(s[0] == '+' || s[0] == '-')
        return false;
    else {
    	string tmp = s.substr(0, pos_point);
    	if(!tmp.empty() && !isInteger(tmp))
    		return false;
    }
    for(int i = pos_point + 1; i < s.length(); ++i) {
        if(!isDigit(s[i]))
            return false;
    }
    return true;
}

bool isNumber(string s) {
	s = noSpace(s);
	if(s.empty())
		return false;
    int pos_e = -1;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'e') {
            if(pos_e == -1)
                pos_e = i;
            else
                return false;
        }
    }
    if(pos_e == -1)
        return isInteger(s) || isFloat(s);
    else if(pos_e == 0 || pos_e == s.length() - 1)
    	return false;
    else {
        string s1, s2;
        s1 = s.substr(0, pos_e);
        s2 = s.substr(pos_e + 1, s.length() - pos_e - 1);
        return (isInteger(s1) || isFloat(s1)) && isInteger(s2);
    }
}

int main() {
    string s;
    cout << "Please input the string: ";
    cin >> s;
    bool judge = isNumber(s);
    string s1 = " is number";
    string s2 = " is not number";
    if(judge)
        cout << s << s1 << endl;
    else
        cout << s << s2 << endl;
    return 0;
}
