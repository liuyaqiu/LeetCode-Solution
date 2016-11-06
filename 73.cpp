#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<vector<int>>& res) {
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }x
}

void setZeroes(vector<vector<int>>& matrixA) {
	int m = matrixA.size();
    int n = matrixA[0].size();
    vector<vector<long int>> matrix(m, vector<long int>(n, 0));
    for(int i = 0; i < m; ++i) {
    	for(int j = 0; j < n; ++j) {
    	    matrix[i][j] = matrixA[i][j];
    	}
    }
	long int flag = 2147483648;
    for(int i = 0; i < m; ++i) {
    	for(int j = 0; j < n; ++j) {
    		if(matrix[i][j] == 0) {
    			for(int p = 0; p < m; ++p) {
    				if(matrix[p][j] != 0)
    					matrix[p][j] = flag;
    			}
    			for(int q = 0; q < n; ++q) {
    				if(matrix[i][q] != 0)
    					matrix[i][q] = flag;
    			}
    		}
    	}
    }
    for(int i = 0; i < m; ++i) {
    	for(int j = 0; j < n; ++j) {
    		if(matrix[i][j] == flag)
    			matrix[i][j] = 0;
    	}
    }
    for(int i = 0; i < m; ++i) {
    	for(int j = 0; j < n; ++j) {
    	    matrixA[i][j] = matrix[i][j];
    	}
    }
}

int main() {
	int m;
	int n;
	cout << "Please input m and n: ";
	cin >> m >> n;
	int val;
	vector<vector<int>> matrix(m, vector<int>(n, 0));
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> val;
			matrix[i][j] = val;
		}
	}
	print(matrix);
	setZeroes(matrix);
	print(matrix);
	return 0;
}
