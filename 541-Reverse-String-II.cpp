#include <iostream>
#include <vector>

using namespace std;

void reverse(string& s, int start, int end) {
    int n = s.length();
    int low = start;
    int high = min(end - 1, n - 1);
    while(low < high) {
        swap(s[low], s[high]);
        low++;
        high--;
    }
}

string reverseStr(string s, int k) {
    int n = s.length();
    for(int i = 0; i < n; i += 2 * k) {
        reverse(s, i, i + k);
    }
    return s;
}
