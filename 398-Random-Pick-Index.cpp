#include <iostream>
#include <vector>

using namespace std;

/*
 * Random Pick Index
 *
 * Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
 *
 * Note:
 * The array size can be very large. Solution that uses too much extra space will not pass the judge.
 *
 *
 */

class Solution {
private:
    vector<int> array;

public:
    Solution(vector<int> nums): array(nums) {
        srand(time(0));
    }

    int pick(int target) {
        while(true) {
            int index = rand() % array.size();
            if(target == array[index])
                return index;
        }
    }
};

