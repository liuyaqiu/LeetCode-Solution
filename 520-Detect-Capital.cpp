#include <iostream>
#include <vector>

using namespace std;

bool isLower(char c) {
    return c - 'a' >= 0 && c - 'a' < 26;
}

bool isUpper(char c) {
    return c - 'A' >= 0 && c - 'A' < 26;
}

bool detectCapitalUse(string word) {
    int lower = 0, uppper = 0;   
    int n = word.length();
    for(int i = 0; i < n; i++) {
        char c = word[i];
        if(isLower(c))
            lower += 1;
        if(isUpper(c))
            uppper += 1;
    }
    if(uppper > 1)
        return lower == 0;
    else if(uppper == 0)
        return true;
    else
        return isUpper(word[0]);
}
