#include <iostream>
#include <vector>

using namespace std;

/*
 * Reverse Vowels of a String
 *
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 *
 * Note:
 * The vowels does not include the letter "y".
 *
 *
 */

bool isVowels(char c) {
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for(int i = 0; i < vowels.size(); i++)
        if(c == vowels[i])
            return true;
    return false;
}

string reverseVowels(string s) {
    int low = 0, high = s.length() - 1;
    do {
        while(low < high && !isVowels(s[low]))
            low++;
        while(low < high && !isVowels(s[high]))
            high--;
        if(low < high) {
            char c = s[low];
            s[low] = s[high];
            s[high] = c;
            low++;
            high--;
        }
    } while(low < high);
    return s;
}

int main() {
    string s;
    cin >> s;
    string res = reverseVowels(s);
    cout << res << endl;
    return 0;
}

