p/*
  K Empty Slots

  There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

  Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

  For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

  Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

  If there isn't such day, output -1.

  Example 1:
  Input:
  flowers: [1,3,2]
  k: 1
  Output: 2
  Explanation: In the second day, the first and the third flower have become blooming.
  Example 2:
  Input:
  flowers: [1,2,3]
  k: 1
  Output: -1
  Note:
  The given array will be in the range [1, 20000]

 */

#include <iostream>
#include <vector>

using namespace std;

int gap(vector<int>& flowers, int day) {
    int n = flowers.size();
    vector<bool> status(n, false);
    for(int i = 0; i < day; i++)
        status[flowers[i] - 1] = true;
    int pos = 0;
    while(pos < n && !status[pos])
        pos++;
    int maxi = pos;
    while(pos < n && status[pos]) {
        int end = pos + 1;
        while(end < n && !status[end])
            end++;
        maxi = max(maxi, end - pos - 1);
        pos = end;
    }
    return maxi;
}

bool valid(vector<int>& flowers, int day, int k) {
    int n = flowers.size();
    vector<bool> status(n, false);
    for(int i = 0; i < day; i++)
        status[flowers[i] - 1] = true;
    int pos = 0;
    while(pos < n && !status[pos])
        pos++;
    while(pos < n && status[pos]) {
        int end = pos + 1;
        while(end < n && !status[end])
            end++;
        if(end < n && end - pos - 1 == k)
            return true;
        pos = end;
    }
    return false;
}

int solve(vector<int>& flowers, int k, int l, int r) {
    int low = l;
    int high = r;
    while(low <= high) {
        int mid = (low + high) / 2;
        int check = gap(flowers, mid);
        if(check < k)
            high = mid - 1;
        else {
            if(valid(flowers, mid, k)) {
                int tmp = solve(flowers, k, low, mid - 1);
                if(tmp != -1)
                    return tmp;
                else
                    return mid;
            }
            else {
                int r1 = solve(flowers, k, low, mid - 1);
                int r2 = solve(flowers, k, mid + 1, high);
                if(r1 != -1) {
                    if(r2 != -1)
                        return min(r1, r2);
                    else
                        return r1;
                }
                else
                    return r2;
            }
        }
    }
    return -1;
}

int kEmptySlots(vector<int>& flowers, int k) {
    if(k > flowers.size() - 2)
        return -1;
    return solve(flowers, k, 1, flowers.size());
}
