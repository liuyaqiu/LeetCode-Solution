
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        for (int i = 1; i < S.length(); i++) {
            if (i > 10) {
                break;
            }
            if (S[0] == '0' && i != 1) {
                continue;
            }
            for (int j = i + 1; j < S.length(); j++) {
                if (j - i > 10) {
                    break;
                }
                if ((S[i] == '0' && j - i != 1)) {
                    continue;
                }
                long long f1 = stoll(S.substr(0, i));
                long long f2 = stoll(S.substr(i, j - i));
                if (f1 >= pow(2, 31) || f2 >= pow(2, 31)) {
                    continue;
                }
                int index = j;
                vector<int> res = {int(f1), int(f2)};
                while (index < S.length()) {
                    long long tmp = f2;
                    f2 += f1;
                    f1 = tmp;
                    if (f2 >= pow(2, 31)) {
                        break;
                    }
                    string cur = to_string(f2);
                    if (S[index] == '0' && f2 != 0) {
                        break;
                    }
                    if (S.find(cur, index) != index) {
                        break;
                    } else {
                        res.push_back(f2);
                        index += cur.length();
                    }
                }
                if (index == S.length()) {
                    return res;
                }
            }
        }
        return {};
    }
};