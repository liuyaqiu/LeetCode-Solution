#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>

using namespace std;

/*
 * Binary Watch
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the right.
 *
 * Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
 *
 * Example:
 *
 * Input: n = 1
 * Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 * Note:
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
 *
 *
 */

string getTime(int hours, int minutes) {
    char str[4];
    sprintf(str, "%d:%02d", hours, minutes);
    string res = str;
    return res;
}

int countDigits(int n) {
    int cnt = 0;
    while(n != 0) {
        cnt += n & 1;
        n = n >> 1;
    }
    return cnt;
}

vector<string> readBinaryWatch(int num) {
    vector<string> res;
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 60; j++) {
            if(countDigits((i << 6) + j) == num)
                res.push_back(getTime(i, j));
        }
    }
    return res;
}

template <typename T> void print(vector<T>& res) {
    for(auto s: res)
        cout << s << " ";
    cout << endl;
}

int main() {
    int num;
    cin >> num;
    vector<string> res = readBinaryWatch(num);
    print(res);
    return 0;
}
