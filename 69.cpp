#include <iostream>
#include <string>
#include <vector>

using namespace std;

long int mySqrt(long int n) {
	if(n == 0)
		return 0;
    if(n < 4)
        return 1;
    long int left = 1, right = n / 2;
    while(left < right) {
        long int medium = (left + right) / 2;
        long int val = medium * medium;
        if(val == n)
            return medium;
        else if(val < n) {
            left = medium + 1;
        }
        else {
            right = medium - 1;
        }
    }
    if(left * left <= n)
    	return left;
    else
    	return left - 1;
}

int main() {
    int n;
    cout << "Please input n: ";
    cin >> n;
    cout << "The square root is :" << mySqrt(n) << endl;
    return 0;
}
