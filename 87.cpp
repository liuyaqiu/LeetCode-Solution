#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

typedef pair<int, int> Pair;

int leftPos(string s1, string s2) {
    int len = s1.length();
    map<char, int> map1;
    map<char, int> map2;
    int l_pos = 0;
    while(l_pos < len) {
        if(map1.find(s1[l_pos]) != map1.end()) {
            map1[s1[l_pos]] += 1;
        }
        else {
            map1.insert(pair<char, int>(s1[l_pos], 1));
        }
        if(map2.find(s2[l_pos]) != map2.end()) {
            map2[s2[l_pos]] += 1;
        }
        else {
            map2.insert(pair<char, int>(s2[l_pos], 1));
        }
        if(map1 == map2) {
        	return l_pos;
        }
        else
            l_pos += 1;
    }
    return l_pos;
}

int rightPos(string s1, string s2) {
	int len = s1.length();
	int r_pos = len - 1;
	map<char, int> map1;
	map<char, int> map2;
    while(r_pos >= 0) {
        if(map1.find(s1[r_pos]) != map1.end()) {
            map1[s1[r_pos]] += 1;
        }
        else {
            map1.insert(pair<char, int>(s1[r_pos], 1));
        }
        int pos2 = len - 1 - r_pos;
        if(map2.find(s2[pos2]) != map2.end()) {
            map2[s2[pos2]] += 1;
        }
        else {
            map2.insert(pair<char, int>(s2[pos2], 1));
        }
        if(map1 == map2) {
            return r_pos;
        }
        else
            r_pos -= 1;
    }
    return r_pos;
}

bool isScramble(string s1, string s2) {
	int len = s1.length();
	if(s1 == s2)
		return true;
	int left = leftPos(s1, s2);
	if(left < len - 1)
		if(isScramble(s1.substr(0, left + 1), s2.substr(0, left + 1)) && isScramble(s1.substr(left + 1, len - left - 1), s2.substr(left + 1, len - left - 1)))
			return true;
	int right = rightPos(s1, s2);
	if(right > 0)
		if(isScramble(s1.substr(right, len - right), s2.substr(0, len - right)) && isScramble(s1.substr(0, right), s2.substr(len - right, right)))
			return true;
	return false;
}

int main() {
    string s1, s2;
    cout << "Input s1 and s2: ";
    cin >> s1 >> s2;
    if(isScramble(s1, s2)) {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}

//vfldiodffghyq vdgyhfqfdliof
//oatzzffqpnwcxhejzjsnpmkmzngneo acegneonzmkmpnsjzjhxwnpqffzzto