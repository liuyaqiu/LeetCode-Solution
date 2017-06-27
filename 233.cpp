#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countDigitOne(int n) {
    if(n < 1)
        return 0;
    if(n < 10)
        return 1;
    long num = n;
    long k = log10(n);
    long res = 1;
    for(int i = 1; i < k; i++)
        res = pow(10, i) + 10 * res;
    long head = num / long(pow(10, k));
    long tail = num % long(pow(10, k));
    if(head == 1)
        return res + 1 + tail + countDigitOne(tail);
    else
        return pow(10, k) + head * res + countDigitOne(tail);
}

int main() {
    int num;
    cin >> num;
    int res = countDigitOne(num);
    cout << res << endl;
    return 0;
}
