/*
 * Container With Most Water
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 */

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

