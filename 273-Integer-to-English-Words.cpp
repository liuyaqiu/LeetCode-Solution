#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

/*
 * Integer to English Words
 *
 * Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
 *
 * For example,
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * Hint:
 *
 * Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
 * Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
 * There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
 *
 *
 */

string convert(int num) {
    vector<string> digit = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string res = "";
    if(num == 0)
        return digit[0];
    if(num >= 100) {
        int hund = num / 100;
        res = res + digit[hund] + " Hundred ";
        num = num % 100;
    }
    if(num > 0 && num < 20)
        res = res + digit[num] + " ";
    else {
        int ten = num / 10;
        if(ten >= 2)
            res = res + tens[ten - 2] + " ";
        int one = num % 10;
        if(one > 0)
            res = res + digit[one];
    }
    int pos = res.length() - 1;
    while(pos >= 0 && res[pos] == ' ')
    	pos--;
    return res.substr(0, pos + 1);
}

string numberToWords(int num) {
    if(num < 1000)
        return convert(num);
    vector<int> chunk = {0, 0, 0, 0};
    for(int i = 3; i >= 1; i--) {
        chunk[i] = num % 1000;
        num = num / 1000;
    }
    chunk[0] = num;
    vector<string> scale = {"Billion", "Million", "Thousand", ""};
    string res;
    for(int i = 0; i < 4; i++) {
        if(chunk[i] > 0) {
            res = res +  " " + convert(chunk[i]) + " " + scale[i];
        }
    }
    int start = 0;
    while(start < res.length() && res[start] == ' ')
    	start++;
    int end = res.length() - 1;
    while(end >= 0 && res[end] == ' ')
    	end--;
    return res.substr(start, end - start + 1);
}

int main() {
    int num;
    cin >> num;
    string res = numberToWords(num);
    cout << "'" << res << "'" << endl;
    return 0;
}
