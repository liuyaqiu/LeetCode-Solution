#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

/*
 * Queue Reconstruction by Height
 *
 * Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 *
 * Note:
 * The number of people is less than 1,100.
 *
 * Example
 *
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 *
 *
 */

typedef pair<int, int> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) {
        if(lhs.first != rhs.first)
            return lhs.first < rhs.first;
        else
            return lhs.second > rhs.second;
    }
};

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), comp());
    list<mypair> res;
    while(!people.empty()) {
        mypair cur = people.back();
        if(res.empty())
            res.push_back(cur);
        else {
            int delta = cur.second;
            auto iter = next(res.begin(), delta);
            res.insert(iter, cur);
        }
        people.pop_back();
    }
    return vector<pair<int, int>>(res.begin(), res.end());
}

int main() {
    int h, k;
    vector<mypair> people;
    while(cin >> h >> k)
        people.push_back(mypair(h, k));
    vector<mypair> res = reconstructQueue(people);
    for(auto item: res)
        cout << item.first << " " << item.second << endl;
    cout << endl;
    return 0;
}

