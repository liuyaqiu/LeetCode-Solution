#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> Point;

Point nextPoint(Point cur, int& left, int& right, int& up, int& down) {
    int x = get<0>(cur);
    int y = get<1>(cur);
    int d = get<2>(cur);
    switch(d) {
        case 0:
            if(x <= left) {
                if(up > down - 1)
                    return Point(-1, -1, -1); //end
                else {
                    down -= 1;
                    return Point(x, y - 1, 2); //switch to up
                }
            }
            else {
                return Point(x - 1, y, d);
            }
            break;
        case 1:
            if(x >= right) {
                if(up + 1 > down)
                    return Point(-1, -1, -1);
                else {
                    up += 1;
                    return Point(x, y + 1, 3);
                }
            }
            else {
                return Point(x + 1, y, d);
            }
            break;
        case 2:
            if(y <= up) {
                if(left + 1 > right)
                    return Point(-1, -1, -1);
                else {
                    left += 1;
                    return Point(x + 1, y, 1);
                }
            }
            else {
                return Point(x, y - 1, d);
            }
            break;
        case 3:
            if( y >= down) {
                if(left > right - 1)
                    return Point(-1, -1, -1);
                else {
                    right -= 1;
                    return Point(x - 1, y, 0);
                }
            }
            else {
                return Point(x, y + 1, d);
            }
            break;
        default:
            return Point(-1, -1, -1);
            break;
    }
}

int getValue(vector<vector<int>>& matrix, Point p) {
    int i = get<0>(p);
    int j = get<1>(p);
    return matrix[j][i];
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
    Point cur = Point(0, 0, 1);
    Point end = Point(-1, -1, -1);
    int val;
    vector<int> res;
    while(cur != end) {
        val = getValue(matrix, cur);
        res.push_back(val);
        cur = nextPoint(cur, left, right, up, down);
    }
    return res;
}

void print(vector<int>& nums) {
	for(auto iter = nums.begin(); iter != nums.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

int main() {
	int m, n;
	cout << "Please input the row and col of matrix: ";
	cin >> m >> n;
	int val;
    vector<vector<int>> matrix(m);
    for(int i = 0; i < m; i += 1) {
        for(int j = 0; j < n; j += 1) {
            cin >> val;
            matrix[i].push_back(val);
        }
    }
    for(auto iter = matrix.begin(); iter != matrix.end(); ++iter) {
        print(*iter);
    }
    vector<int> res = spiralOrder(matrix);
    print(res);
    return 0;
}
