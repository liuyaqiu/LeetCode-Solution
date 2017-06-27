#include <iostream>
#include <vector>

using namespace std;

/*
 * Split Array Largest Sum
 *
 * Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
 *
 * Note:
 * If n is the length of array, assume the following constraints are satisfied:
 *
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 * Examples:
 *
 * Input:
 * nums = [7,2,5,10,8]
 * m = 2
 *
 * Output:
 * 18
 *
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 *
 *
 */

int splitArray(vector<int>& nums, int m) {
    int high = 0;
    for(auto num: nums)
        high += num;
    int low = high / m;
    while(low <= high) {
        int mid = (low + high) / 2;
        int cnt = m;    //监控当前剩余子数组的数量
        int partia_sum = 0;     //监控当前正在计数的子数组的数组和
        bool valid = true;
        for(auto num: nums) {
            if(num > mid) {
                valid = false;
                break;
            }
            if(cnt + num > mid) {   //当前子数组的和已经超过mid，开始下一个子数组计数，更新子数组的和
                cnt -= 1;
                partia_sum = 0;
            }
            partia_sum += num;
            if(cnt == 0) {
                valid = false;
                break;
            }
            if(valid)
                high = mid - 1;     //存在一种子数组的分割使得各个子数组的和不小于mid，high缩小为mid - 1
            else
                low = mid + 1;  //不存在一种一种合理的分割，low更新为mid + 1;
        }
    }
    return low;
}
