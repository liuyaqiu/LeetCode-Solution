class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() < 2) {
            return chars.size();
        }
        int index = 0;
        int cnt = 0;
        int compressed_index = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (chars[i] == chars[index]) {
                cnt += 1;
            } else {
                if (cnt > 1) {
                    int max_digit = std::floor(std::log10(cnt));
                    int cur_digit = (cnt / int((std::pow(10.0, max_digit)))) % 10;
                    chars[compressed_index++] = chars[index];
                    while (max_digit >= 0) {
                        chars[compressed_index++] = '0' + cur_digit;
                        max_digit -= 1;
                        if (max_digit < 0) {
                            break;
                        }
                        cur_digit = (cnt / int((std::pow(10.0, max_digit)))) % 10;
                    }
                } else if(cnt == 1) {
                    chars[compressed_index++] = chars[index];
                }
                index = i;
                cnt = 1;
            }
        }
        if (cnt > 1) {
            int max_digit = std::floor(std::log10(cnt));
            int cur_digit = (cnt / int((std::pow(10.0, max_digit)))) % 10;
            chars[compressed_index++] = chars[index];
            while (max_digit >= 0) {
                chars[compressed_index++] = '0' + cur_digit;
                max_digit -= 1;
                if (max_digit < 0) {
                    break;
                }
                cur_digit = (cnt / int((std::pow(10.0, max_digit)))) % 10;
            }
        } else if(cnt == 1) {
            chars[compressed_index++] = chars[index];
        }
        return compressed_index;
    }
};