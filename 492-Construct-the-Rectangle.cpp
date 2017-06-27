#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> constructRectangle(int area) {
    int w = sqrt(area);
    while(area % w != 0)
        w--;
    return {area / w, w};
}
