class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> count;
        for (int num : answers) {
            if (count.find(num) == count.end())  {
                count[num] = 0;
            }
            count[num] += 1;
        }
        for (auto c : count) {
            if (c.second == 0) {
                res += 1;
            } else {
                res += ceil(c.second * 1.0 / (c.first + 1)) * (c.first + 1);
            }
        }
        return res;
    }
};