#include <iostream>
#include <vector>

using namespace std;

void eval(vector<int>& cnt, string num, int times) {
    for(int j = 0; j < num.length(); j++) {
        cnt[num[j] - 'a'] -= times;
    }
}

string originalDigits(string s) {
    vector<int> cnt(26, 0);
    for(int i = 0; i < s.length(); i++)
        cnt[s[i] - 'a'] += 1;
    vector<int> res(10, 0);
    vector<string> nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<int> digit = {2, 0, 6, 7, 8, 3, 4, 5, 1, 9};
    vector<char> flag = {'w', 'z', 'x', 's', 'g', 't', 'u', 'f', 'o', 'i'};
    for(int i = 0; i < 10; i++) {
        int val = cnt[flag[i] - 'a'];
        res[digit[i]] = val;
        eval(cnt, nums[digit[i]], val);
    }
    string str = "";
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < res[i]; j++) {
            str += '0' + i;
        }
    }
    return str;
}

int main() {
    string s;
    cin >> s;
    string res = originalDigits(s);
    cout << res << endl;
    return 0;
}

