/*
  Repeated String Match

  Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

  For example, with A = "abcd" and B = "cdabcdab".

  Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

  Note:
  The length of A and B will be between 1 and 10000.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int repeatedStringMatch(string A, string B) {
    if(A.length() >= B.length()) {
        if(A.find(B, 0) != -1)
            return 1;
        else {
            A = A + A;
            if(A.find(B, 0) != -1)
                return 2;
            else
                return -1;
        }
    }
    int pos = B.find(A, 0);
    if(pos == -1)
        return -1;
    int left = 0;
    string tmp = B.substr(0, pos);
    if(!tmp.empty() && A.find(tmp, 0) != A.length() - tmp.length())
        return -1;
    if(pos > 0)
        left = 1;
    int mid = 0;
    int prev = 0;
    while(pos != -1) {
        mid += 1;
        prev = pos + A.length();
        pos = B.find(A, prev);
    }
    int right = 0;
    if(prev < B.length()) {
        if(A.find(B.substr(prev, B.length() - prev), 0) != 0)
            return -1;
        else
            right = 1;
    }
    return left + mid + right;
}
