#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) {
        return lhs.first > rhs.first;
    }
};

bool isLower(char c) {
    return c - 'a' >= 0 && c - 'a' < 26;
}

bool isUpper(char c) {
    return c - 'A' >= 0 && c - 'A' < 26;
}

bool isDigit(char c) {
    return c - '0' >= 0 && c - '0' < 10;
}

int strongPasswordChecker(string s) {
    int totalCnt = s.length();
    int lowers = 0, uppers = 0, digits = 0;
    for(int i = 0; i < totalCnt; i++) {
        char c = s[i];
        if(isLower(c))
            lowers = 1;
        else if(isUpper(c))
            uppers = 1;
        else if(isDigit(c))
            digits = 1;
    }
    int typeCnt = lowers + uppers + digits;
    vector<int> tmp;
    int pos = 0;
    while(pos < totalCnt) {
        int start = pos;
        while(pos < totalCnt && s[pos] == s[start])
            pos++;
        if(pos - start >= 3)
            tmp.push_back(pos - start);
    }
    if(totalCnt < 6) {
        for(auto n: tmp) {
            if(n == 5)
                return max(2, 3 - typeCnt);
        }
        return max(6 - totalCnt, 3 - typeCnt);
    }
    priority_queue<mypair, vector<mypair>, comp> repeats;
    for(auto num: tmp)
        repeats.push(mypair(num % 3, num));
    int deleteCnt = max(totalCnt - 20, 0);
    while(!repeats.empty() && totalCnt > 20) {
        int m = repeats.top().first, r = repeats.top().second;
        repeats.pop();
        int delta = min(m + 1, totalCnt - 20);
        totalCnt -= delta;
        repeats.push(mypair(2, r - delta));
    }
    int changeCnt = 0;
    while(!repeats.empty()) {
        changeCnt += repeats.top().second / 3;
        repeats.pop();
    }
    return deleteCnt + max(changeCnt, 3 - typeCnt);
}

int main() {
    string s;
    cin >> s;
    int res = strongPasswordChecker(s);
    cout << res << endl;
    return 0;
}
