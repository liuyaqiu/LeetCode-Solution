class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        if (A.empty()) {
            return true;
        }
        int start = 0;
        while (start < A.length()) {
            int index = start;
            bool is_rotate = true;
            for (int i = 0; i < B.length(); i++) {
                if (A[(i + index) % A.length()] != B[i]) {
                    is_rotate = false;
                    break;
                }
            }
            if (is_rotate) {
                return true;
            }
            start += 1;
        }
        return false;
    }
};