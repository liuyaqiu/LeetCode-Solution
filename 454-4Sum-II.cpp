#include <iostream>
#include <vector>
#include <map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    map<int, int> sum;
    int n = A.size();
    for(auto a: A) {
        for(auto b: B) {
            int num = a + b;
            if(sum.find(num) == sum.end())
                sum[num] = 1;
            else
                sum[num] += 1;
        }
    }
    int cnt = 0;
    for(auto c: C) {
    	for(auto d: D) {
    		auto iter = sum.find(-(c + d));
    		if(iter != sum.end())
    			cnt += iter->second;
    	}
    }
    return cnt;
}

