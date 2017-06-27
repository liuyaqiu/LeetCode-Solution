#include <iostream>
#include <vector>
#include <random>

using namespace std;

/*
 * Shuffle an Array
 *
 * Shuffle a set of numbers without duplicates.
 *
 * Example:
 *
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 */

class Solution {
private:
    vector<int> origin;
    vector<int> cur;
    default_random_engine generator;
    uniform_int_distribution<int> distribution;

public:
    Solution(vector<int> nums): origin(nums), cur(nums), generator(0) {
        distribution = uniform_int_distribution<int>(0, origin.size() - 1);
    }

    vector<int> reset() {
        cur = origin;
        return cur;
    }

    vector<int> shuffle() {
        for(int i = 0; i < cur.size(); i++) {
            int j = distribution(generator);
            swap(cur[i], cur[j]);
        }
        return cur;
    }
};

