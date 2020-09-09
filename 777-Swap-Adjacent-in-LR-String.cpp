class Solution {
public:
    bool canTransform(string start, string end) {
        int start_r_cnt = 0, end_r_cnt = 0;
        int start_l_cnt = 0, end_l_cnt = 0;
        for (int i = 0; i < start.length(); i++) {
            if (end[i] != 'X') {
                if (end[i] == 'R') {
                    end_r_cnt += 1;
                } else {
                    end_l_cnt += 1;
                }
            }
            if (start[i] != 'X') {
                if (start[i] == 'R') {
                    start_r_cnt += 1;
                    if (start_l_cnt != end_l_cnt) {
                        return false;
                    }
                } else {
                    start_l_cnt += 1;
                    if (start_r_cnt != end_r_cnt) {
                        return false;
                    }
                }
            }
            if (end[i] == 'R' && end_r_cnt > start_r_cnt) {
                return false;
            }
            if (start[i] == 'L' && end_l_cnt < start_l_cnt) {
                return false;
            }
        }
        return start_r_cnt == end_r_cnt && start_l_cnt == end_l_cnt;
    }
};