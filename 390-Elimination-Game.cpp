#include <iostream>
#include <vector>

using namespace std;

/*
 * Elimination Game
 *
 * There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
 *
 * Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
 *
 * We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
 *
 * Find the last number that remains starting with a list of length n.
 *
 * Example:
 *
 * Input:
 * n = 9,
 * 1 2 3 4 5 6 7 8 9
 * 2 4 6 8
 * 2 6
 * 6
 *
 * Output:
 * 6
 *
 *
 */

int lastRemaining(int n) {
    int start = 1, end = n;
    int delta = 2;
    bool right = true;
    while(start < end) {
        if(right) {
            if(((end - start) & (delta - 1)) == 0)
                end -= delta >> 1;
            start += delta >> 1;
        }
        else {
            if(((end - start) & (delta - 1)) == 0)
                start += delta >> 1;
            end -= delta >> 1;
        }
        right = !right;
        delta <<= 1;
    }
    return start;
}

int main() {
    int n;
    cin >> n;
    int res = lastRemaining(n);
    cout << res << endl;
    return 0;
}
