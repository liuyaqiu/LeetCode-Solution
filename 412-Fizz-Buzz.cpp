#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
 * Write a program that outputs the string representation of numbers from 1 to n.
 *
 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
 *
 *
 */

vector<string> fizzBuzz(int n) {
    vector<string> res(n, "");
    for(int i = 0; i < n; i++) {
        stringstream ss;
        ss << i + 1;
        string cur;
        ss >> cur;
        res[i] = cur;
    }
    for(int i = 2; i < n; i += 3)
        res[i] = "Fizz";
    for(int i = 4; i < n; i += 5)
        res[i] = "Buzz";
    for(int i = 14; i < n; i += 15)
        res[i] = "FizzBuzz";
    return res;
}
