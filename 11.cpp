#include <vector>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int getArea(vector<int>& height, int start, int end) {
	return (end - start) * min(height[start], height[end]);
}

int maxArea(vector<int> &height) {
	int start = 0;
	int end = height.size() - 1;
	bool isLeft = height[start] < height[end];
	int max = getArea(height, start, end);
	while(start < end) {
		int tmpPos;
		if(isLeft) {
			tmpPos = start;
			while(start < end && height[start] <= height[tmpPos])
				start += 1;
			int area = getArea(height, start, end);
			if(area > max)
				max = area;
			isLeft = height[start] < height[end];
		}
		else {
			tmpPos = end;
			while(end > start && height[end] <= height[tmpPos])
				end -= 1;
			int area = getArea(height, start, end);
			if(area > max)
				max = area;
			isLeft = height[start] < height[end];
		}
	}
	return max;
}

