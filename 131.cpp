#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;
    while(left < right) {
        if(str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

void addPalindrome(string s, int start, vector<string>& partition, vector<vector<string>>& result) {
    if(start == s.length()) {
        result.push_back(partition);
        return;
    }
    for(int i = start + 1; i <= s.length(); i++) {
        string str = s.substr(start, i - start);
        if(isPalindrome(str)) {
            partition.push_back(str);
            addPalindrome(s, i, partition, result);
            partition.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    if(s.empty())
        return result;
    vector<string> partition;
    addPalindrome(s, 0, partition, result);
    return result;
}

void print(vector<vector<string>>& res) {
    for(auto iter1 = res.begin(); iter1 != res.end(); iter1++) {
        for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++) {
            cout << *iter2 << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    string s;
    cin >> s;
    vector<vector<string>> result = partition(s);
    print(result);
    return 0;
}
