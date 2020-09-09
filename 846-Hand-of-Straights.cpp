class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.empty() || hand.size() % W != 0) {
            return false;
        }
        map<int, int> num_and_count;
        for (int card : hand) {
            if (!num_and_count.count(card)) {
                num_and_count[card] = 0;
            }
            num_and_count[card] += 1;
        }
        vector<pair<int, int>> nums;
        for (const auto& n_and_c : num_and_count) {
            nums.push_back(n_and_c);
        }
        int index = 0;
        while (index < nums.size()) {
            int cur = index;
            int count = nums[index].second;
            while (cur < nums.size() && cur - index < W
                   && nums[cur].first == nums[index].first + cur - index
                   && nums[cur].second >= count) {
                nums[cur].second -= count; 
                cur++;
            }
            if (cur - index != W) {
                return false;
            }
            while (index < nums.size() && nums[index].second == 0) {
                index++;
            }
        }
        return true;
    }
};