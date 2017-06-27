#include <iostream>
#include <vector>

using namespace std;

/*
 * Ransom Note
 *
 * Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 *
 * Each letter in the magazine string can only be used once in your ransom note.
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 *
 *
 */

bool canConstruct(string ransomNote, string magazine) {
    vector<int> cnt1(52, 0);
    vector<int> cnt2(52, 0);
    for(int i = 0; i < ransomNote.length(); i++) {
        char c = ransomNote[i];
        if(c - 'a' >= 0 && c - 'a' < 26)
            cnt1[c - 'a'] += 1;
        else
            cnt1[c - 'A' + 26] += 1;
    }
    for(int i = 0; i < magazine.length(); i++) {
        char c = magazine[i];
        if(c - 'a' >= 0 && c - 'a' < 26)
            cnt2[c - 'a'] += 1;
        else
            cnt2[c - 'A' + 26] += 1;
    }
    for(int i = 0; i < 52; i++) {
        if(cnt1[i] > cnt2[i])
            return false;
    }
    return true;
}

int main() {
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;
    bool res = canConstruct(ransomNote, magazine);
    cout << res << endl;
    return 0;
}
