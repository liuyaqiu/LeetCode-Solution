#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    if(s.empty())
        return 0;
	int start = -1;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] != ' ') {
			start = i;
			break;
		}
	}
	if(start == -1)
		return 0;
	else
		s = s.substr(start, s.length() - start);
	cout << start << endl;
	int end = -1;
	for(int i = s.length() - 1; i >= 0; --i) {
		if(s[i] != ' ') {
			end = i;
			break;
		}
	}
	if(end == -1)
		return 0;
	else
		s = s.substr(0, end + 1);
	cout << end << endl;
	int pos = s.length() - 1;
	while(pos >= 0 && s[pos] != ' ')
		pos -= 1;
	cout << pos << endl;
	if(pos == -1)
		return s.length();
	else
		return s.length() - 1 - pos;
}

int main() {
	string s= "  abc  ";
	cout << lengthOfLastWord(s) << endl;
	return 0;
}