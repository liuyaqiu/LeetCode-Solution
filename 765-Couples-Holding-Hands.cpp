/*
  Couples Holding Hands

  N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

  The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

  The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

  Example 1:

  Input: row = [0, 2, 1, 3]
  Output: 1
  Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
  Example 2:

  Input: row = [3, 2, 0, 1]
  Output: 0
  Explanation: All couples are already seated side by side.
  Note:

  len(row) is even and in the range of [4, 60].
  row is guaranteed to be a permutation of 0...len(row)-1.

 */

#include <iostream>
#include <vector>

using namespace std;

int minSwapsCouples(vector<int>& row) {
    int blocks = 0;
    vector<int> neighbors(row.size(), 0);
    for(int i = 0; i < row.size(); i += 2) {
        neighbors[row[i]] = row[i + 1];
        neighbors[row[i + 1]] = row[i];
    }
    vector<bool> visit(row.size(), false);
    for(int i = 0; i < row.size(); i += 2) {
        if(visit[row[i]])
            continue;
        blocks += 1;
        int start = row[i], end = row[i + 1];
        visit[row[i]] = true;
        visit[row[i + 1]] = true;
        int next = -1;
        if(start % 2 == 0)
            next = start + 1;
        else
            next = start - 1;
        //如果next已经是end，说明已经形成了环
        while(next != end) {
            visit[next] = true;
            start = neighbors[next];
            visit[start] = true;
            if(start % 2 == 0)
                next = start + 1;
            else
                next = start - 1;
        }
    }
    return row.size() / 2 - blocks;
}
