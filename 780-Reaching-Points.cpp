class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        queue<pair<int, int>> que;
        que.push(make_pair(tx, ty));
        while (!que.empty()) {
            const pair<int, int> top = que.front();
            if (top.first == sx && top.second == sy) {
                return true;
            }
            que.pop();
            if (top.first == sx) {
                int n = (top.second - sy) / sx;
                if (n >= 0 && top.second == n * sx + sy) {
                    return true;
                } else {
                    continue;
                }
            }
            if (top.second == sy) {
                int n = (top.first - sx) / top.second;
                if (n >= 0 && top.first == sx + n * sy) {
                    return true;
                } else {
                    continue;
                }
            }
            int x1 = top.first;
            int y1 = - top.first + top.second;
            int x2 = top.first - top.second;
            int y2 = top.second;
            if (x1 >= sx && y1 >= sy) {
                que.push(make_pair(x1, y1));
            }
            if (x2 >= sx && y2 >= sy) {
                que.push(make_pair(x2, y2));
            }
        }
        return false;
    }
};

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // 分析: 如果存在A --> B 且 B --> C，且B < C，则必定存在B --> C，因为A, B, C在同一个域中，通一个域中的元素必定是联通的。
        // 因此试图让(tx, ty)变为(sx, ty')或者(tx', sy)即可简化判断，若tx == sx，那么只需判断ty >= sy以及(ty - sy) % sx,
        // 而ty == sy同理。
        while (sx < tx && sy < ty) {
            if (tx > ty) {
                tx = tx % ty;
            } else {
                ty = ty % tx;
            }
        }
        if (tx == sx) {
            return ty >= sy && (ty - sy) % sx == 0;
        }
        if (ty == sy) {
            return tx >= sx && (tx - sx) % sy == 0;
        }
        return false;
    }
};