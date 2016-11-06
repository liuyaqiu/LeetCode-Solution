#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getLine(vector<string>& words, int& pos, int maxWidth) {
    //cout << "Pos: " << pos << endl;
    int len = words[pos].length();
    int i = pos + 1;
    while(i < words.size() && len <= maxWidth) {
        len += words[i].length() + 1;
        i += 1;
    }
    if(len <= maxWidth) {
        string res = words[pos];
        for(int j = pos + 1; j < i; ++j) {
            res += ' ';
            res += words[j];
        }
        pos = i;
        return res.append(maxWidth - res.size(), ' ');
    }
    i -= 1;
    len -= words[i].length() + 1;
    //cout << len << " " << i << endl;
    int cnt = (i - 1) - pos;
    if(cnt == 0) {
    	int tmp = pos;
        pos += 1;
        return words[tmp].append(maxWidth - len, ' ');
    }
    else {
        int len_sum = len - cnt;
        int k = (maxWidth - len_sum) / cnt;
        //cout << len_sum << " " << k << endl;
        int n = (maxWidth - len_sum) % cnt;
        string res = words[pos];
        for(int j = pos + 1; j < i; ++j) {
            if(n > 0) {
                res.append(k + 1, ' ');
                n -= 1;
            }
            else
                res.append(k, ' ');
            res += words[j];
        }
        pos = i;
        return res;
    }
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int pos = 0;
    vector<string> res;
    while(pos < words.size()) {
        res.push_back(getLine(words, pos, maxWidth));
    }
    return res;
}

void print(vector<string>& lines) {
    for(auto iter = lines.begin(); iter != lines.end(); ++iter) {
        cout << *iter<< endl;
    }
}

int main() {
    int n;
    cout << "Please input the number: ";
    cin >> n;
    string val;
    vector<string> words;
    while(n > 0) {
        cin >> val;
        words.push_back(val);
        n -= 1;
    }
    print(words);
    cout << "Please input the maxWidth: ";
    int maxWidth;
    cin >> maxWidth;
    vector<string> res = fullJustify(words, maxWidth);
    print(res);
    return 0;
}
