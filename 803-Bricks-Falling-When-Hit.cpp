const int maxn = 100000;
int bin[maxn];
int sz[maxn];
void init(int size){
    for (int i=0; i<=size; i++){
        bin[i]=i;
        sz[i]=1;
    }
}

int findX(int x){
    int r=x;
    while (bin[r]!=r) {
        r=bin[r];
    }
    return r;
}

int zip2(int x){
    int tmp, _x = x;
    while ( bin[_x]!=_x )
        _x = bin[_x];
    while ( bin[x]!=x ){
        tmp = bin[x];
        bin[x] = _x;
        x = tmp;
    }
    return _x;
}

void merge(int a,int b) {
    int aRoot=findX(a);
    int bRoot=findX(b);
    if (aRoot==bRoot) return;
    if (aRoot > bRoot) {
        bin[aRoot] = bRoot;
        sz[bRoot] += sz[aRoot];
    } else {
        bin[bRoot] = aRoot;
        sz[aRoot] += sz[bRoot];
    }
    zip2(a);
    zip2(b);
}

class Solution {
public:
  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
      vector<vector<int>> last_grid(grid);
      for (const auto& hit : hits) {
          last_grid[hit[0]][hit[1]] = 0;
      }
      int m = grid.size();
      int n = grid.back().size();
      init(m * n + 1); // source point index is 0
      for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
              if (last_grid[i][j] == 0) {
                  continue;
              }
              int index = i * n + j;
              if (i - 1 >= 0 && last_grid[i - 1][j] == 1) {
                  merge((i - 1) * n + j + 1, index + 1);
              }
              if (i + 1 < m && last_grid[i + 1][j] == 1) {
                  merge((i + 1) * n + j + 1, index + 1);
              }
              if (j - 1 >= 0 && last_grid[i][j - 1] == 1) {
                  merge(i * n + j - 1 + 1, index + 1);
              }
              if (j + 1 < n && last_grid[i][j + 1] == 1) {
                  merge(i * n + j + 1 + 1, index + 1);
              }
              if (i == 0) {
                  merge(index + 1, 0); // connected to the source point.
              }
          }
      }
      vector<int> res(hits.size(), 0);
      for (int i = hits.size() - 1; i >= 0; i--) {
          int x = hits[i][0];
          int y = hits[i][1];
          if (grid[x][y] == 0) {
              continue;
          }
          int source_size = sz[0];
          int index = x * n + y;
          last_grid[x][y] = 1;
          if (x - 1 >= 0 && last_grid[x - 1][y] == 1) {
              merge((x - 1) * n + y + 1, index + 1);
          }
          if (x + 1 < m && last_grid[x + 1][y] == 1) {
              merge((x + 1) * n + y + 1, index + 1);
          }
          if (y - 1 >= 0 && last_grid[x][y - 1] == 1) {
              merge(x * n + y - 1 + 1, index + 1);
          }
          if (y + 1 < n && last_grid[x][y + 1] == 1) {
              merge(x * n + y + 1 + 1, index + 1);
          }
          if (x == 0) {
              merge(index + 1, 0);
          }
          if (sz[0] > source_size) {
              res[i] = sz[0] - source_size - 1;
          }
      }
      return res;
  }
};
