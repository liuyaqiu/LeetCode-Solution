#include <iostream>
#include <vector>

using namespace std;

/*
 * Number of Segments in a String
 *
 * Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
 *
 * Please note that the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 *
 *
 */

int countSegments(string s) {
    int cnt = 0;
    int pos = 0;
    int n = s.length();
    while(pos < n) {
        while(pos < n && s[pos] == ' ')
            pos++;
        if(pos < n)
            cnt++;
        while(pos < n && s[pos] != ' ')
            pos++;
    }
    return cnt;
}
