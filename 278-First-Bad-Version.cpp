#include <iostream>
#include <vector>

using namespace std;

/*
 * First Bad Version
 *
 * You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 *
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 *
 * You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 *
 *
 */

bool isBadVersion(int version) {
    return true;
}

int binarySearch(int start, int end) {
    int mid = (start + end) / 2;
    if(isBadVersion(mid)) {
        if(!isBadVersion(mid - 1))
            return mid;
        else
            return binarySearch(start, mid - 1);
    }
    else
        return binarySearch(mid + 1, end);
}

int firstBadVersion(int n) {
    return binarySearch(1, n);
}
