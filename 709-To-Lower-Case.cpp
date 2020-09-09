/*
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
 *
 *  
 *
 *  Example 1:
 *
 *  Input: "Hello"
 *  Output: "hello"
 *  Example 2:
 *
 *  Input: "here"
 *  Output: "here"
 *  Example 3:
 *
 *  Input: "LOVELY"
 *  Output: "lovely"
 *
 */
#include <string>

using namespace std;

string toLowerCase(string str) {
    string res = "";
    for(int i = 0; i < str.length(); i++) {
        if(str[i] - 'A' >= 0 && str[i] - 'A' < 26)
            res = res + char(str[i] - 'A' + 'a');
        else
            res = res + str[i];
    }
    return res;
}
