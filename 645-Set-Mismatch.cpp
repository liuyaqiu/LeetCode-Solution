/*
  Set Mismatch

  The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

  Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

  Example 1:
  Input: nums = [1,2,2,4]
  Output: [2,3]
  Note:
  The given array size will in the range [2, 10000].
  The given array's numbers won't have any order.

 */

vector<int> findErrorNums(vector<int>& nums) {
    int dup = 0;
    for(int i = 0; i < nums.size() && dup == 0; i++) {
        int pos = i;
        while(nums[pos] != pos + 1) {
            if(nums[pos] != nums[nums[pos] - 1]) {
                swap(nums[pos], nums[nums[pos] - 1]);
            }
            else {
                dup = nums[pos];
                break;
            }
        }
    }
    int tmp = 0;
    for(int i = 0; i < nums.size(); i++) {
        tmp ^= (i + 1);
        tmp ^= nums[i];
    }
    tmp ^= dup;
    vector<int> res = {dup, tmp};
    return res;
}
