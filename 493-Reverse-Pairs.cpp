#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class FenwickTree {
private:
    vector<long> tree;

public:
    FenwickTree(long n) {
        tree = vector<long>(n + 1, 0);
    }

    void add(long x, long val) {
        while(x < (long)tree.size()) {
            tree[x] += val;
            x += lowbit(x);
        }
    }

    long lowbit(long x) {
        return x & -x;
    }

    long sum(long x) {
        long res = 0;
        while(x > 0) {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }
};

long reversePairs(vector<int>& nums) {
    set<long> tmp;
    for(auto num: nums) {
        tmp.insert(num);
        tmp.insert(2 * long(num));
    }
    unordered_map<long, long> dmap;
    long index = 1;
    for(auto item: tmp)
        dmap[item] = index++;
    FenwickTree ft(dmap.size());
    int res = 0;
    for(auto iter = nums.rbegin(); iter != nums.rend(); iter++) {
        res += ft.sum(dmap[*iter] - 1);
        ft.add(dmap[long(*iter) * 2], 1);   //将当前元素置入
    }
    return res;
}

int main() {
    long val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    long res = reversePairs(nums);
    cout << res << endl;
    return 0;
}
