class ExamRoom {
public:
    ExamRoom(int N) {
        interval_start_and_cnt[0] = N;
        cnt_to_start[N] = {0};
        N_ = N;
    }

    int seat() {
        auto iter = cnt_to_start.begin();
        if (iter->first % 2 == 0 && next(iter, 1) != cnt_to_start.end() && next(iter, 1)->first == iter->first - 1
           && *(iter->second.begin()) > *(next(iter, 1)->second.begin())) {
            advance(iter, 1);
        }
        int start = *(iter->second.begin());
        int cnt = interval_start_and_cnt[start];
        int first_cnt = (cnt - 1) / 2;
        if (interval_start_and_cnt.count(0) && interval_start_and_cnt[0] - 1 > (cnt - 1) / 2) {
            start = 0;
            first_cnt = interval_start_and_cnt[0] - 1;
        }
        auto last_iter = prev(interval_start_and_cnt.end());
        if (last_iter->first + last_iter->second == N_ && last_iter->second - 1 > first_cnt) {
            start = last_iter->first;
        }
        cnt = interval_start_and_cnt[start];
        iter = cnt_to_start.find(cnt);
        if (cnt == 1) {
            interval_start_and_cnt.erase(start);
            iter->second.erase(start);
            if (iter->second.empty()) {
                cnt_to_start.erase(cnt);
            }
            return start;
        } else {
            if (start == 0 || (cnt == 2 && start + interval_start_and_cnt[start] != N_)) {
                interval_start_and_cnt[start + 1] = cnt - 1;
                if (!cnt_to_start.count(cnt - 1)) {
                    cnt_to_start[cnt - 1] = {};
                }
                cnt_to_start[cnt - 1].insert(start + 1);
                interval_start_and_cnt.erase(start);
                iter->second.erase(start);
                if (iter->second.empty()) {
                    cnt_to_start.erase(cnt);
                }
                return start;
            } else if (start + interval_start_and_cnt[start] == N_) {
                interval_start_and_cnt[start] = cnt - 1;
                if (!cnt_to_start.count(cnt - 1)) {
                    cnt_to_start[cnt - 1] = {};
                }
                cnt_to_start[cnt - 1].insert(start);
                iter->second.erase(start);
                if (iter->second.empty()) {
                    cnt_to_start.erase(cnt);
                }
                return N_ - 1;
            } else {
                int new_start = start + (cnt % 2 == 0 ? cnt / 2 - 1 : cnt / 2);
                interval_start_and_cnt[start] = new_start - start;
                interval_start_and_cnt[new_start + 1] = start + cnt - (new_start + 1);
                if (!cnt_to_start.count(new_start - start)) {
                    cnt_to_start[new_start - start] = {};
                }
                cnt_to_start[new_start - start].insert(start);
                if (!cnt_to_start.count(start + cnt - (new_start + 1))) {
                    cnt_to_start[start + cnt - (new_start + 1)] = {};
                }
                cnt_to_start[start + cnt - (new_start + 1)].insert(new_start + 1);
                iter->second.erase(start);
                if (iter->second.empty()) {
                    cnt_to_start.erase(cnt);
                }
                return new_start;
            }
        }
    }
    
    void leave(int p) {
        auto iter = interval_start_and_cnt.lower_bound(p);
        int cnt = iter->second;
        if (iter->first == p + 1) {
            interval_start_and_cnt.erase(p + 1);
            interval_start_and_cnt[p] = cnt + 1;
            if (!cnt_to_start.count(cnt + 1)) {
                cnt_to_start[cnt + 1] = {};
            }
            cnt_to_start[cnt + 1].insert(p);
            cnt_to_start[cnt].erase(p + 1);
            if (cnt_to_start[cnt].empty()) {
                cnt_to_start.erase(cnt);
            }
        } else {
            interval_start_and_cnt[p] = 1;
            if (!cnt_to_start.count(1)) {
                cnt_to_start[1] = {};
            }
            cnt_to_start[1].insert(p);
        }
        auto cur_iter = interval_start_and_cnt.lower_bound(p);
        if (cur_iter != interval_start_and_cnt.begin()) {
            auto prev_iter = prev(cur_iter, 1);
            if (prev_iter->first + prev_iter->second == p) {
                cnt_to_start[prev_iter->second].erase(prev_iter->first);
                if (cnt_to_start[prev_iter->second].empty()) {
                    cnt_to_start.erase(prev_iter->second);
                }
                prev_iter->second += cur_iter->second;
                if (!cnt_to_start.count(prev_iter->second)) {
                    cnt_to_start[prev_iter->second] = {};
                }
                cnt_to_start[prev_iter->second].insert(prev_iter->first);
                cnt_to_start[cur_iter->second].erase(cur_iter->first);
                if (cnt_to_start[cur_iter->second].empty()) {
                    cnt_to_start.erase(cur_iter->second);
                }
                interval_start_and_cnt.erase(p);
            }
        }
    }
private:
    map<int, int> interval_start_and_cnt;
    map<int, set<int>, std::greater<int>> cnt_to_start;
    int N_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */