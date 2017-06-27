#include <iostream>
#include <vector>
#include <string>

using namespace std;

string lowercase(string s) {
    string res = "";
    for(int i = 0; i < s.length(); i++) {
        int tmp = s[i] - 'A';
        if(tmp >= 0 && tmp < 26)
            res += tmp + 'a';
        else
            res += s[i];
    }
    return res;
}

bool isValid(char c) {
    int tmp1 = c - '0';
    int tmp2 = c - 'a';
    return (tmp1 >= 0 && tmp1 < 10) || (tmp2 >= 0 && tmp2 < 6);
}

bool isIPv4(string IP, vector<int> pos) {
    if(pos.size() != 4)
        return false;
    int n = IP.length();
    pos.push_back(n);
    for(int i = 0; i < n; i++) {
        if(IP[i] != '.' && (IP[i] - '0' < 0 || IP[i] - '0' >= 10))
            return false;
    }
    for(int i = 1; i < pos.size(); i++) {
        string cur;
        cur = IP.substr(pos[i - 1] + 1, pos[i] - pos[i - 1] - 1);
        if(cur.empty() || cur.size() > 3)
            return false;
        if(cur.size() > 1 && cur[0] == '0')
            return false;
        int val = stoi(cur);
        if(val < 0 || val > 0xff)
            return false;
    }
    return true;
}

bool isIPv6(string IP, vector<int> pos) {
    if(pos.size() != 8)
        return false;
    int n = IP.length();
    pos.push_back(n);
    for(int i = 1; i < pos.size(); i++) {
        string cur;
        cur = IP.substr(pos[i - 1] + 1, pos[i] - pos[i - 1] - 1);
        if(cur.empty() || cur.size() > 4)
            return false;
        int val = stoi(cur, 0, 16);
        if(val < 0 || val > 0xffff)
            return false;
    }
    return true;
}

string validIPAddress(string IP) {
    IP = lowercase(IP);
    int n = IP.length();
    vector<int> dot{-1};
    vector<int> colon{-1};
    for(int i = 0; i < n; i++) {
        if(IP[i] == '.')
            dot.push_back(i);
        else if(IP[i] == ':')
            colon.push_back(i);
        else {
            if(!isValid(IP[i]))
                return "Neither";
        }
    }
    if(dot.size() > 1 && colon.size() > 1)
        return "Neither";
    if(dot.size() > 1 && isIPv4(IP, dot))
        return "IPv4";
    if(colon.size() > 1 && isIPv6(IP, colon))
        return "IPv6";
    return "Neither";
}

int main() {
    string s;
    cin >> s;
    string res = validIPAddress(s);
    cout << res << endl;
    return 0;
}
