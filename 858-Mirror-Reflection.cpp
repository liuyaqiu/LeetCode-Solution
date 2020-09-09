int gcd(int a, int b) {
    while (a % b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return b;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int x = lcm(p, q) / q;
        int y = lcm(p, q) / p;
        if (y % 2 == 1) {
            if (x % 2 == 0) {
                return 2;
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    }
};