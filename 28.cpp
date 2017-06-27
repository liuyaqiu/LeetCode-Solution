#include <iostream>
#include <vector>
#include <string>

using namespace std;

int strStr(string haystak, string needle) {
    if(haystak.empty()) {
        if(needle.empty())
            return 0;
        else
            return -1;
    }
    int i = 0;
    int pos = haystak.length() - needle.length();
    while(i < pos) {
        if(haystak.substr(i, needle.length()) == needle)
            return i;
        i += 1;
    }
    return -1;
}
