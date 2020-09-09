/*
 * Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.
 *
 * Example:
 *
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 * Note: 
 * You may assume that nums' length ≥ k-1 and k ≥ 1.
 *
 *
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
    private:
    priority_queue<int, vector<int>, greater<int>> que;
    int que_size;
    
    public:
    KthLargest(int k, vector<int> nums) {
        que_size = k + 1;
        for(auto item: nums) {
            que.push(item);
            if(que.size() >= que_size)
                que.pop();
        }
    }
    
    int add(int val) {
        que.push(val);
        if(que.size() >= que_size)
            que.pop();
        return que.top();
    }
};
