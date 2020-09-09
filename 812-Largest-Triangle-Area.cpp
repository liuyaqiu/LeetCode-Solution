class Solution {
public:
    vector<int> coef(int x1, int y1, int x2, int y2) {
        return {y2 - y1, -(x2 - x1), y1 * (x2 - x1) - x1 * (y2 - y1)};
    }

    double distance(int x1, int y1, int x2, int y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    continue;
                }
                vector<int> coefs = coef(points[i][0], points[i][1], points[j][0], points[j][1]);
                int max_dis = 0;
                for (int k = j + 1; k < points.size(); k++) {
                    max_dis = max(max_dis, abs(coefs[0] * points[k][0] + coefs[1] * points[k][1] + coefs[2]));
                }
                res = max(res, 0.5 * distance(points[i][0], points[i][1], points[j][0], points[j][1]) * max_dis / sqrt(coefs[0] * coefs[0] + coefs[1] * coefs[1]));
            }
        }
        return res;
    }
};