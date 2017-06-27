#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string convertoBase7(int num) {
	if(num == 0)
		return "0";
	bool minus = (num < 0);
	num = abs(num);
    string res = "";
    while(num > 0) {
        int cur = num % 7;
        res = to_string(cur) + res;
        num /= 7;
    }
    if(minus)
    	res = "-" + res;
    return res;
}

