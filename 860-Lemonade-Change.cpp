class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> count(3, 0); // count of $5, $10, $20
        for (int bill : bills) {
            if (bill == 5) {
                count[0] += 1;
            } else if (bill == 10) {
                if (count[0] == 0) {
                    return false;
                }
                count[0] -= 1;
                count[1] += 1;
            } else {
                if (count[1] >= 1) {
                    count[1] -= 1;
                    if (count[0] == 0) {
                        return false;
                    }
                    count[0] -= 1;
                } else {
                    if (count[0] >= 3) {
                        count[0] -= 3;
                    } else {
                        return false;
                    }
                }
                count[2] += 1;
            }
        }
        return true;
    }
};