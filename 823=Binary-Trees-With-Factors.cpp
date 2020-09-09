int mod = 1000000007;

long long count(int target, const unordered_set<int>& nums, unordered_map<int, long long>& num_to_count) {
    if (num_to_count.count(target)) {
        return num_to_count[target];
    }
    long long res = 1; // as root
    for (const int num : nums) {
        if (target % num == 0 && nums.count(target / num)) {
            res = (res + count(num, nums, num_to_count) * count(target / num, nums, num_to_count)) % mod;
        }
    }
    num_to_count[target] = res;
    return res;
}

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_set<int> nums;
        for (int num : A) {
            nums.insert(num);
        }
        unordered_map<int, long long> num_to_count;
        long long res = 0;
        for (int num : A) {
            res = (res + count(num, nums, num_to_count)) % mod;
        }
        return res;
    }
};