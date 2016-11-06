#include <string.h>
#include <iostream>
#include <string>

using namespace std;

string intToRoman(int num) {
    string str("");
    while(num >= 1000) {
        num -= 1000;
        str.append("M");
    }
    while(num >= 100) {
        if(num >= 900) {
            num -= 900;
            str.append("CM");
        }
        else if(num >= 500) {
            num -= 500;
            str.append("D");
        }
        else if(num >= 400) {
            num -= 400;
            str.append("CD");
        }
        else {
            num -= 100;
            str.append("C");
        }
    }
    while(num >= 10) {
        if(num >= 90) {
            num -= 90;
            str.append("XC");
        }
        else if(num >= 50) {
            num -= 50;
            str.append("L");
        }
        else if(num >= 40) {
            num -= 40;
            str.append("XL");
        }
        else {
            num -= 10;
            str.append("X");
        }
    }
    while(num >= 1) {
        if(num >= 9) {
            num -= 9;
            str.append("IX");
        }
        else if(num >= 5) {
            num -= 5;
            str.append("V");
        }
        else if(num >= 4) {
            num -= 4;
            str.append("IV");
        }
        else {
            num -= 1;
            str.append("I");
        }
    }
    return str;
}

int main() {
    int num;
    cout << "Please input the num: ";
    cin >> num;
    string roman = intToRoman(num); 
    cout << "The Roman is: " << roman << endl;
    return 0;
}
