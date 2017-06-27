#include <iostream>
#include <vector>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int all = (D - B) * (C - A) + (G - E) * (H - F);
    if(C < E || G < A || D < F || H < B)
        return all;
    int left = max(A, E);
    int right = min(C, G);
    int top = min(H, D);
    int bottom = max(B, F);
    int repeat = (right - left) * (top - bottom);
    return all - repeat;
}
