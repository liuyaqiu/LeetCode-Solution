#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <unordered_set>

using namespace std;

int digitSum(int n) {
    stringstream ss;
    ss << n;
    string str;
    ss >> str;
    int res = 0;
    for(int i = 0; i < str.length(); i++) {
        res += pow(str[i] - '0', 2) ;
    }
    return res;
}

bool isHappy(int n) {
    unordered_set<int> refer;
    refer.insert(n);
    while(true) {
        n = digitSum(n);
        if(n == 1)
            return true;
        if(refer.find(n) != refer.end())
            return false;
        else
            refer.insert(n);
    }
}
