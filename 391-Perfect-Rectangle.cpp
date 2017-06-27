#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
 * Perfect Rectangle
 *
 * Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.
 *
 * Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).
 *
 *
 * 本题的最直接想法是划定最终围成的可能面积，然后对面积内的每一个小正方形区域进行访问，看是否有未覆盖的区域或者被多次覆盖的区域。
 *
 * 但是这种方式会面临一个问题，就是时间复杂度与围成的长方形的最大可能面积成正比，时间复杂度过高。
 *
 * 这道题应该采用交点法。
 * 依次访问每个小矩形的四个顶点
 * 容易知道，矩形邻接顶点只有几种合法的位置关系：
 * 计四个顶点分别为A(左下），B（左上），C（右下），D（右上）
 * A-C-B-D, A-B, A-D, C-D, B-C
 * 可以用令左上角的值为1, 左下角的值为2，右上角的值为4，右下角的值为8
 * 则合法的顶点值为：
 * 1, 2, 4, 8 (大矩形的顶点）
 * A-B: 1 + 2 = 3
 * A-C: 1 + 4 = 5
 * C-D: 4 + 8 = 12
 * B-D: 2 + 8 = 10
 * A-B-C-D: 15
 */

typedef pair<int, int> mypair;

bool judge(int val) {
    return (val == 1 || val == 2 || val == 3 || val == 4 || val == 5 || val == 8 || val == 10 || val == 12 || val == 15);
}

bool isRectangleCover(vector<vector<int>>& rectangles) {
    map<mypair, int> points;
    for(auto rec: rectangles) {
        int x1 = rec[0];
        int y1 = rec[1];
        int x2 = rec[2];
        int y2 = rec[3];
        vector<mypair> p(4, mypair());
        p[0] = mypair(x1, y1);
        p[1] = mypair(x1, y2);
        p[2] = mypair(x2, y1);
        p[3] = mypair(x2, y2);
        for(int i = 0; i < 4; i++) {
            //cout << p[i].first << " " << p[i].second << endl;
            int val = 1 << i;
            if(points.find(p[i]) == points.end())
                points[p[i]] = val;
            else
                points[p[i]] += val;
        }
    }
    int cnt = 0;
    for(auto p: points) {
        int val = p.second;
        //cout << "(" << p.first.first << ", " << p.first.second << "): "<< p.second << endl;
        if(!judge(val))
            return false;
        else {
            if((val & (val - 1)) == 0)
                cnt += val;
        }
    }
    //cout << cnt << endl;
    return cnt == 15;
}

int main() {
    vector<vector<int>> rectangles;
    int x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> x2 >> y2) {
        vector<int> rec = {x1, y1, x2, y2};
        rectangles.push_back(rec);
    }
    bool res = isRectangleCover(rectangles);
    cout << res << endl;
    return 0;
}
