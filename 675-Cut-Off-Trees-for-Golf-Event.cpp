/*
  Cut Off Trees for Golf Event

  You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

  0 represents the obstacle can't be reached.
  1 represents the ground can be walked through.
  The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
  You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

  You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

  You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <cmath>

using namespace std;

typedef pair<int, int> coord;
typedef pair<int, coord> mypair;

struct comp {
    bool operator() (const mypair& lhs, const mypair& rhs) const {
        return lhs.first > rhs.first;
    }
};

struct comp2 {
    bool operator() (const coord& lhs, const coord& rhs) const {
        if(lhs.first != rhs.first)
            return lhs.first < rhs.first;
        else
            return lhs.second < rhs.second;
    }
};

struct comp3 {
    bool operator() (const mypair& lhs, const mypair& rhs) {
        return lhs.first < rhs.first;
    }
};

bool valid(vector<vector<int>>& forest) {
    if(forest[0][0] == 0)
        return false;
    int m = forest.size(), n = forest.front().size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<coord> tmp;
    tmp.push(coord(0, 0));
    visited[0][0] = true;
    while(!tmp.empty()) {
        coord cur = tmp.front();
        tmp.pop();
        int i = cur.first, j = cur.second;
        if(i - 1 >= 0 && forest[i - 1][j] > 0 && !visited[i - 1][j]) {
            visited[i - 1][j] = true;
            tmp.push(coord(i - 1, j));
        }
        if(i + 1 < m && forest[i + 1][j] > 0 && !visited[i + 1][j]) {
            visited[i + 1][j] = true;
            tmp.push(coord(i + 1, j));
        }
        if(j - 1 >= 0 && forest[i][j - 1] > 0 && !visited[i][j - 1]) {
            visited[i][j - 1] = true;
            tmp.push(coord(i, j - 1));
        }
        if(j + 1 < n && forest[i][j + 1] > 0 && !visited[i][j + 1]) {
            visited[i][j + 1] = true;
            tmp.push(coord(i, j + 1));
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            if(forest[i][j] > 0 && !visited[i][j])
                return false;
    }
    return true;
}

int heuristic(const coord& x, const coord& y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

vector<coord> neighbors(vector<vector<int>>& forest, const coord& cur) {
    int m = forest.size(), n = forest[0].size();
    vector<coord> res;
    int i = cur.first, j = cur.second;
    if(i - 1 >= 0 && forest[i - 1][j] > 0)
        res.push_back(coord(i - 1, j));
    if(i + 1 < m && forest[i + 1][j] > 0)
        res.push_back(coord(i + 1, j));
    if(j - 1 >= 0 && forest[i][j - 1] > 0)
        res.push_back(coord(i, j - 1));
    if(j + 1 < n && forest[i][j + 1] > 0)
        res.push_back(coord(i, j + 1));
    return res;
}

int asearch(vector<vector<int>>& forest, coord start, coord goal) {
    set<coord> closed_set;
    priority_queue<mypair, vector<mypair>, comp> open_set;
    map<coord, int, comp2> gscore, fscore;
    open_set.push(mypair(forest[start.first][start.second], start));
    gscore[start] = 0;
    fscore[start] = gscore[start] + heuristic(start, goal);
    while(!open_set.empty()) {
        coord cur = open_set.top().second;
        if(cur == goal)
            return fscore[cur];
        open_set.pop();
        closed_set.insert(cur);
        for(auto neighbor: neighbors(forest, cur)) {
            if(closed_set.find(neighbor) != closed_set.end())
                continue;
            int new_g = gscore[cur] + 1;
            if(gscore.find(neighbor) != gscore.end() && new_g >= gscore[neighbor])
                continue;
            gscore[neighbor] = new_g;
            fscore[neighbor] = gscore[neighbor] + heuristic(neighbor, goal);
            open_set.push(mypair(fscore[neighbor], neighbor));
        }
    }
    return -1;
}

int cutOffTree(vector<vector<int>>& forest) {
    if(!valid(forest))
        return -1;
    vector<mypair> trees;
    int m = forest.size(), n = forest[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(forest[i][j] > 1)
                trees.push_back(mypair(forest[i][j], coord(i, j)));
        }
    }
    sort(trees.begin(), trees.end(), comp3());
    int res = asearch(forest, coord(0, 0), trees[0].second);
    for(int i = 0; i < trees.size() - 1; i++) {
        int tmp = asearch(forest, trees[i].second, trees[i + 1].second);
        res += tmp;
    }
    return res;
}
