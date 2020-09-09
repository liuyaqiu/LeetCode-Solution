class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x_left = max(rec1[0], rec2[0]);
        int x_right = min(rec1[2], rec2[2]);
        int y_bottom = max(rec1[1], rec2[1]);
        int y_up = min(rec1[3], rec2[3]);
        return x_right > x_left && y_up > y_bottom;
    }
};