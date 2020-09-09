class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 1;
        int prev_index = -1;
        int index = 0;
        while (index < seats.size()) {
            while (index < seats.size() && seats[index] == 0) {
                index++;
            }
            if (index >= seats.size()) {
                break;
            }
            if (prev_index < 0) {
                res = max(res, index);
            } else {
                res = max(res, (index - prev_index + 1) / 2);
            }
            while(index < seats.size() && seats[index] == 1) {
                index++;
            }
            prev_index = index;
        }
        if (prev_index < seats.size()) {
            res = max(res, int(seats.size()) - prev_index);
        }
        return res;
    }
};