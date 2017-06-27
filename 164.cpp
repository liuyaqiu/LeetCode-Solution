#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bucket {
    int low;
    int high;
    Bucket(): low(-1), high(-1) {}
};

int maximumGap(vector<int>& nums) {
    if(nums.size() < 2)
        return 0;
    int tmax = nums[0];
    int tmin = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        tmin = min(tmin, nums[i]);
        tmax = max(tmax, nums[i]);
    }
    if(tmax - tmin == 0)
    	return 0;
    vector<Bucket> buckets = vector<Bucket>(nums.size() + 1, Bucket());
    double interval = nums.size() * 1.0 / (tmax - tmin);
    for(int i = 0; i < nums.size(); i++) {
        int index = (int)((nums[i] - tmin) * interval);
        if(buckets[index].low == -1) {
            buckets[index].low = nums[i];
            buckets[index].high = nums[i];
        }
        else {
            buckets[index].low = min(buckets[index].low, nums[i]);
            buckets[index].high = max(buckets[index].high, nums[i]);
        }
    }
    int res = 0;
    int prev = buckets[0].high;
    /*
     1. 每个桶内的元素间的间隔不超过(max - min) / n
     2. 显然至少有两个相邻元素间的间隔超过(max - min) / n。假设所有相邻元素间的间隔不超过(max - min) / n，那么n个元素的最大总间隔为(n - 1) * (max - min) / n < (max - min)，矛盾。
     3. 由1和2综合知道必定有相邻元素的间隔超过(max - min) / n，而且这样的元素必定分布在相邻的两个桶中。
     4. 由3知道扫描每个相邻桶的差值(bucket[i].low - bucket[i - 1].high, i和i - 1都不是空桶)，其中的最大值即为相邻元素的最大差值。
     */
    for(int i = 1; i < buckets.size(); i++) {
        if(buckets[i].low != -1) {
            res = max(res, buckets[i].low - prev);
            prev = buckets[i].high;
        }
    }
    return res;
}
