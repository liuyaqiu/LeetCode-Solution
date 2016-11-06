#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if(s1.empty())
        return s2 == s3;
    if(s2.empty())
        return s1 == s3;
    if(s3.empty())
        return false;
    char c1 = s1[0], c2 = s2[0], c3 = s3[0];
    int cnt3 = 0;
    for(int i = 0; i < s3.length() && s3[i] == c3; ++i)
        cnt3 += 1;
    if(c1 != c2) {
        if(c3 == c1) {
            int cnt1 = 0;
            while(cnt1 < s1.length() && s1[cnt1] == c1 && cnt1 < cnt3)
                cnt1 += 1;
            if(cnt1 < cnt3)
                return false;
            else
                return isInterleave(s1.substr(cnt3, s1.length() - cnt3), s2, s3.substr(cnt3, s3.length() - cnt3));
        }
        else if(c3 == c2) {
            int cnt2 = 0;
            while(cnt2 < s2.length() && s2[cnt2] == c2 && cnt2 < cnt3)
                cnt2 += 1;
            if(cnt2 < cnt3)
                return false;
            else
                return isInterleave(s1, s2.substr(cnt3, s2.length() - cnt3), s3.substr(cnt3, s3.length() - cnt3));
        }
        else
            return false;
    }
    else {
        if(c3 != c1)
            return false;
        else {
            int cnt1 = 0;
            while(cnt1 < s1.length() && s1[cnt1] == c1)
                cnt1 += 1;
            int cnt2 = 0;
            while(cnt2 < s2.length() && s2[cnt2] == c2)
                cnt2 += 1;
            for(int k = 0; k <= cnt3; ++k) {
                if(k <= cnt1 && cnt3 - k <= cnt2) {
                    if(isInterleave(s1.substr(k, s1.length() - k), s2.substr(cnt3 - k, s2.length() - cnt3 + k), s3.substr(cnt3, s3.length() - cnt3)))
                        return true;
                }
            }
            return false;
        }
    }
}

int main() {
    string s1, s2, s3;
    cout << "Please input s1, s2, s3: ";
    cin >> s1 >> s2 >> s3;
    if(isInterleave(s1, s2, s3))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
