#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <map>

using namespace std;

struct data {
    char c;
    int cnt;
    data(char _c = '.', int _cnt = -1) {
        c = _c;
        cnt = _cnt;
    }
};

void print(list<data>& li) {
    for(auto item: li) {
        cout << item.c << ":= " << item.cnt << endl;
    }
    cout << endl;
}

void cleanBoard(list<data>& li) {
    auto it = li.begin();
    while(it != li.end()) {
        if(it == li.begin()) {
            if(it->cnt >= 3)
                it = li.erase(it);
            else
                ++it;
        }
        else {
            //检查是否发生前项归并
            if(it->c == prev(it)->c) {
                it->cnt += prev(it)->cnt;
                li.erase(prev(it));
            }
            else {
                if(it->cnt >= 3)
                    it = li.erase(it);
                else
                    ++it;
            }
        }
    }
    if((int)li.size() == 0)
        return;
    it = --li.end();
    if(it->cnt >= 3)
        li.erase(it);
}

int dfs(list<data>& li, map<char, int>& mp, const int& kMaxNeed) {
    cleanBoard(li);
    if((int)li.size() == 0)
        return 0;
    int minNeed = kMaxNeed;
    for(auto& item: li) {
        int need = 3 - item.cnt;
        if(mp.count(item.c) != 0 && mp[item.c] >= need) {
            mp[item.c] -= need;
            if(mp[item.c] == 0)
                mp.erase(item.c);
            item.cnt += need;
            list<data> liNext = li;
            int ret = dfs(liNext, mp, kMaxNeed);
            minNeed = min(minNeed, ret + need);
            item.cnt -= need;
            if(mp.find(item.c) == mp.end())
                mp[item.c] = need;
            else
                mp[item.c] += need;
        }
    }
    return minNeed;
}

int findMinSetp(string board, string hand) {
    list<data> li;
    int pos = 0;
    int n = board.size();
    while(pos < n) {
        int start = pos;
        while(pos < n && board[pos] == board[start])
            pos++;
        li.push_back(data(board[start], pos - start));
    }
    cleanBoard(li);
    map<char, int> mp;
    for(auto it = hand.begin(); it != hand.end(); it++)
        mp[*it] += 1;
    int kMaxNeed = 6;
    int res = dfs(li, mp, kMaxNeed);
    if(res == kMaxNeed)
        return -1;
    else
        return res;
}

int main() {
    string board, hand;
    cin >> board >> hand;
    int res = findMinSetp(board, hand);
    cout << res << endl;
    return 0;
}
