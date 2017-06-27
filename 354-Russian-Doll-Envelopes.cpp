#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Russian Doll Envelopes
 *
 * You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
 *
 * What is the maximum number of envelopes can you Russian doll? (put one inside other)
 *
 * Example:
 * Given envelopes = [[5,4 6,4 6,7 2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
 *
 *
 */

bool comp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    if(lhs.first != rhs.first)
        return lhs.first < rhs.first;
    else
        return rhs.first > rhs.first;
}

int maxEnvelopes(vector<pair<int ,int>>& envelopes) {
    if(envelopes.empty())
        return 0;
    sort(envelopes.begin(), envelopes.end(), comp);
    vector<pair<int, int>> inc;
    for(auto env: envelopes) {
        if(inc.empty() || env.second > inc.back().second)
            inc.push_back(env);
        int i = 0, j = inc.size() - 1;
        while(i < j) {
            int mid = (i + j) / 2;
            if(inc[mid].second < env.second)
                i = mid + 1;
            else
                j = mid;
        }
        inc[j] = env;
    }
    return inc.size();
}

int main() {
    int w, h;
    vector<pair<int, int>> envs;
    while(cin >> w >> h)
        envs.push_back(pair<int, int>(w, h));
    cout << envs.size() << endl;
    int res = maxEnvelopes(envs);
    cout << res << endl;
    return 0;
}

//15 8 2 20 2 14 4 17 8 19 8 9 5 7 11 19 8 11 13 11 2 13 11 19 8 11 13 11 2 13 11 19 16 1 18 13 14 17 18 19
