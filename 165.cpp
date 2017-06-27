#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int cmpVer(vector<int>& ver1, vector<int>& ver2) {
    int pos = 0;
    while(pos < ver1.size() && pos < ver2.size()) {
        if(ver1[pos] < ver2[pos])
            return -1;
        else if(ver1[pos] > ver2[pos])
            return 1;
        pos++;
    }
    while(pos < ver1.size()) {
        if(ver1[pos] != 0)
            return 1;
        pos++;
    }
    while(pos < ver2.size()) {
        if(ver2[pos] != 0)
            return -1;
        pos++;
    }
    return 0;
}

vector<int> getVersion(string version) {
    int start = 0;
    int end;
    vector<int> res;
    while(start < version.length()) {
        end = start + 1;
        stringstream ss;
        while(end < version.length() && version[end] != '.') {
            end++;
        }
        ss << version.substr(start, end - start);
        int cur;
        ss >> cur;
        res.push_back(cur);
        start = end + 1;
    }
    return res;
}

int compareVersion(string version1, string version2) {
    vector<int> ver1 = getVersion(version1);
    vector<int> ver2 = getVersion(version2);
    return cmpVer(ver1, ver2);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int res = compareVersion(s1, s2);
    cout << res << endl;
    return 0;
}
