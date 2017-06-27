#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkRecord(string s) {
    int pos = s.find('A');
    if(pos != -1 && pos < s.length() - 1) {
        pos = s.find('A', pos + 1);
        if(pos != -1)
            return false;
    }
    pos = s.find("LLL");
    return pos == -1;
}

int main() {
    string s;
    cin >> s;
    bool res = checkRecord(s);
    cout << res << endl;
    return 0;
}
