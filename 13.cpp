#include <string>
#include <iostream>

using namespace std;

int romanToInt(string roman) {
    const char *p = roman.c_str();
    int num = 0;
    while(*p == 'M') {
        p += 1;
        num += 1000;
    }
    if(*p == 'D') {
        p += 1;
        num += 500;
    }
    while(*p == 'C') {
        if(*(p + 1) == 'M') {
            p += 2;
            num += 900;
        }
        else if(*(p + 1) == 'D') {
            p += 2;
            num += 400;
        }
        else {
            p += 1;
            num += 100;
        }
    }
    if(*p == 'L') {
        p += 1;
        num += 50;
    }
    while(*p == 'X') {
        if(*(p + 1) == 'C') {
            p += 2;
            num += 90;
        }
        else if(*(p + 1) == 'L') {
            p += 2;
            num += 40;
        }
        else {
            p += 1;
            num += 10;
        }
    }
    if(*p == 'V') {
        p += 1;
        num += 5;
    }
    while(*p == 'I') {
        if(*(p + 1) == 'X') {
            p += 2;
            num += 9;
        }
        else if(*(p + 1) == 'V') {
            p += 2;
            num += 4;
        }
        else {
            p += 1;
            num += 1;
        }
    }
    return num;
}

int main() {
    string roman;
    cout << "Please input the roman: ";
    cin >> roman;
    cout << "The number is: " << romanToInt(roman) << endl;
    return 0;
}
