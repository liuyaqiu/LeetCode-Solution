#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define inf numeric_limits<int>::max()

void print(vector<vector<int>>& matrix) {
    for(auto row: matrix) {
        for(auto item: row)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}

int dfs(string ring, string key, int ring_pos, int key_pos, vector<vector<int>>& clock, vector<vector<int>>& anticlock) {
    int m = ring.length();
    int n = key.length();
    if(key_pos >= n)
        return 0;
    int res1 = 0;
    if(clock[ring_pos][key_pos] != inf)
        res1 = clock[ring_pos][key_pos];
    else {
        int start = ring_pos;
        while(ring[ring_pos] != key[key_pos])
            ring_pos = (ring_pos + 1) % m;
        res1 += (ring_pos - start + m) % m + 1;
        res1 += dfs(ring, key, ring_pos, key_pos + 1, clock, anticlock);
        ring_pos = start;
        clock[ring_pos][key_pos] = res1;
    }
    int res2 = 0;
    if(anticlock[ring_pos][key_pos] != inf)
        res2 = anticlock[ring_pos][key_pos];
    else {
        int start = ring_pos;
        while(ring[ring_pos] != key[key_pos])
            ring_pos = (ring_pos - 1 + m) % m;
        res2 += (start - ring_pos + m) % m + 1;
        res2 += dfs(ring, key, ring_pos, key_pos + 1, clock, anticlock);
        ring_pos = start;
        anticlock[ring_pos][key_pos] = res2;
    }
    return min(res1, res2);
}

int findRotateSteps(string ring, string key) {
    int m = ring.length();
    int n = key.length();
    vector<vector<int>> clock(m, vector<int>(n, inf));
    vector<vector<int>> anticlock(m, vector<int>(n, inf));
    int res = dfs(ring, key, 0, 0, clock, anticlock);
    return res;
}

int main() {
    string ring, key;
    cin >> ring >> key;
    int res = findRotateSteps(ring, key);
    cout << res << endl;
    return 0;
}
