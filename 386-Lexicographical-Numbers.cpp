#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
 * Lexicographical Numbers
 *
 * Given an integer n, return 1 - n in lexicographical order.
 *
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 *
 * Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
 *
 *
 */

int getLen(int n) {
    return floor(log10(n)) + 1;
}

int cut(int n) {
    n /= 10;
    while(n % 10 == 9)
        n /= 10;
    if(n == 0)
        return n;
    else
        return n + 1;
}

vector<int> lexicalOrder(int n) {
    vector<int> res;
    if(n < 1)
        return res;
    int num = 1;
    int len = getLen(n);
    while(num != 0) {
        if(num > n) {
            num = cut(num);
        }
        else {
            res.push_back(num);
            if(getLen(num) < len) {
                num *= 10;
            }
            else {
                if(num % 10 == 9)
                    num = cut(num);
                else
                    num += 1;
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> res = lexicalOrder(n);
    for(auto item: res)
        cout << item << " ";
    cout << endl;
    return 0;
}
