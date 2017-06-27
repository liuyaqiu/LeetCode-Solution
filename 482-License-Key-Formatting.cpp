#include <iostream>
#include <vector>

using namespace std;

bool isLower(char c) {
    return c - 'a' >= 0 && c - 'a' < 26;
}

string licenseKeyFormatting(string S, int K) {
    string str = "";
    for(int i = 0; i < S.length(); i++) {
        if(S[i] != '-') {
            if(isLower(S[i]))
                str += (S[i] - 'a') + 'A';
            else
                str += S[i];
        }
    }
    int start = 0;
    int n = str.length();
    if(n % K != 0)
        start = n % K;
    string res = "";
    if(start != 0)
        res += str.substr(0, start);
    while(start < n) {
        res += "-" + str.substr(start, K);
        start += K;
    }
    if(res[0] == '-')
        res = res.substr(1, res.length() - 1);
    return res;
}

