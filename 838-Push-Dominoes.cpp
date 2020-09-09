vector<pair<int, int>> push_time(string dominoes) {
    vector<pair<int, int>> res;
    for (int i = 0; i < dominoes.length(); i++) {
        res.push_back({-1, -1});
    }
    for (int i = 0; i < dominoes.length(); i++) {
        int index = i;
        if (dominoes[index] == 'L') {
            while (index >= 0 && dominoes[index] != 'R') {
                if (res[index].first < 0 || res[index].first > i - index) {
                    res[index].first = i - index;
                }
                index--;
            }
        } else if (dominoes[index] == 'R') {
            while (index < dominoes.length() && dominoes[index] != 'L') {
                if (res[index].second < 0 || res[index].second > index - i) {
                    res[index].second = index - i;
                }
                index++;
            }
        }
    }
    return res;
}

class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<pair<int, int>> pushed_time = push_time(dominoes);
        string res;
        for (const auto& left_and_right : pushed_time) {
            if (left_and_right.first < 0) {
                if (left_and_right.second < 0) {
                    res += '.';
                } else {
                    res += 'R';
                }
            } else {
                if (left_and_right.second < 0) {
                    res += 'L';
                } else {
                    if (left_and_right.first < left_and_right.second) {
                        res += 'L';
                    } else if (left_and_right.first > left_and_right.second) {
                        res += 'R';
                    } else {
                        res += '.';
                    }
                }
            }
        }
        return res;
    }
};