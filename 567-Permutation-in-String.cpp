#include <iostream>
#include <vector>

using namespace std;

bool checkInclusion(string s1, string s2) {
    vector<int> cnt1(26, 0);
    int n1 = s1.length();
    int n2 = s2.length();
    for(int i = 0; i < n1; i++) {
        cnt1[s1[i] - 'a'] += 1;
    }
    vector<int> cnt2(cnt1);
    int start = 0;
    int end = 0;
    while(end <= n2) {
        if(end - start < n1) {
        	if(end >= n2) {
        		return false;
        	}
            int pos = s2[end] - 'a';
            //s1中不包含当前字符
            if(cnt1[pos] == 0) {
                cnt2 = cnt1;
                end++;
                start = end;
                continue;
            }
            else {
                //s1中包含当前元素，但是当前元素的数量已经超过，将start移动一位
                while(cnt2[pos] == 0) {
                    cnt2[s2[start] - 'a']++; 
                    start++;
                }
                cnt2[pos]--;
                end++;
            }
        }
        else
            return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    bool res = checkInclusion(s1, s2);
    cout << res << endl;
    return 0;
}

/*
trinitrophenylmethylnitramine
dinitrophenylhydrazinetrinitrophenylmethylnitramine
*/
