/*
  Task Scheduler

  Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

  However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

  You need to return the least number of intervals the CPU will take to finish all the given tasks.

  Example 1:
  Input: tasks = ['A','A','A','B','B','B'], n = 2
  Output: 8
  Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
  Note:
  The number of tasks is in the range [1, 10000].
  The integer n is in the range [0, 100].

 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int select(vector<int>& cnt, vector<bool>& used) {
    int maxi = 0;
    int res = -1;
    for(int i = 0; i < cnt.size(); i++) {
        if(!used[i] && cnt[i] > maxi) {
            maxi = cnt[i];
            res = i;
        }
    }
    return res;
}

int leastInterval(vector<char>& tasks, int n) {
    vector<int> cnt(26, 0);
    int count = 0;
    for(auto task: tasks) {
        cnt[task - 'A'] += 1;
        count += 1;
    }
    // sort(cnt.begin(), cnt.end(), greater<int>());
    queue<int> que;
    vector<bool> used(26, false);
    int res = 0;
    while(que.size() < n + 1 && count > 0) {
        int i = select(cnt, used);
        if(i != -1) {
            used[i] = true;
            cnt[i]--;
            count--;
        }
        que.push(i);
        res += 1;
    }
    while(count > 0) {
        int i = select(cnt, used);
        if(que.front() != -1)
            used[que.front()] = false;
        que.pop();
        que.push(i);
        if(i != -1) {
            used[i] = true;
            cnt[i]--;
            count--;
        }
        res += 1;
    }
    return res;
}
