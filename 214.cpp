#include <string>
#include <vector>
#include <iostream>
using namespace std;

string shortestPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    while(j >= 0) {
        if(s[i] == s[j])
            i++;
        j--;
    }       
    if(i == s.length())
        return s;
    string suffix = s.substr(i, s.length() - i);
    string prefix = "";
    for(int k = 0; k < suffix.length(); k++) {
        prefix = suffix[k] + prefix;
    }
    string mid = shortestPalindrome(s.substr(0, i));
    return prefix + mid + suffix;
}

int main() {
    string s;
    cin >> s;
    string res = shortestPalindrome(s);
    cout << res << endl;
    return 0;
}

    //分析，容易注意到，若s前端含有长度大于1的最大回文子串，则i将会指向该回文子串的下一个位置。从i开始的部分必定不属于可回文置换的部分，计i开始的后段为suffix, 则suffix必定属于s中需要逆置的部分，若i前面的部分已经是回文子串，记为mid，则结果为~suffix + mid + suffix。
    //容易知道，当mid部分不是回文串时，则s的前段不存在长度大于1的回文子串，需要逆置的部分为[1, n)，而i >= 1，显然i以后的部分需要逆置。迭代计算mid部分即可
    //此时res = ~suffix + palindrome(mid) + suffix;
    //该算法设计的精髓在于能够在o(n)时间内找到s前段的回文子串，即使没有最大回文子串，也不会影响最差情况下的迭代计算。
