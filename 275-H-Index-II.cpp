#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * H-Index II
 *
 * Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
 *
 * Hint:
 *
 * Expected runtime complexity is in O(log n) and the input is sorted.
 *
 *
 */

int binarySearch(vector<int>& citations, int start, int end) {
	if(start > end)
		return 0;
    int n = citations.size();
    int mid = (start + end) / 2;
    if(citations[mid] >= n - mid) {
        if(mid == 0)
            return min(n - mid, citations[mid]);
        if(citations[mid - 1] < n - (mid - 1))
            return max(min(n - mid, citations[mid]), min(n - (mid - 1), citations[mid - 1]));
        else
            return binarySearch(citations, start, mid);
    }
    else
        return binarySearch(citations, mid + 1, end);
}

int hIndex(vector<int>& citations) {
    return binarySearch(citations, 0, citations.size() - 1);
}

int main() {
    int val;
    vector<int> citations;
    while(cin >> val) {
        citations.push_back(val);
    }
    int res =hIndex(citations); 
    cout << res << endl;
    return 0;
}
