#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int maxn = 200 + 5;
int bin[maxn];
int sz[maxn];

void init(int size) {
    for(int i = 0; i <= size; i++) {
        bin[i] = i;
        sz[i] = 1;
    }
}

int zip(int x) {
    int root = x;
    while(bin[root] != root)
        root = bin[root];
    while(bin[x] != x) {
        int tmp = bin[x];
        bin[x] = root;
        x = tmp;
    }
    return root;
}

int findX(int x) {
    int root = x;
    while(bin[root] != root) {
        root = bin[root];
    }
    return root;
}

void merge(int a, int b) {
    int root_a = findX(a);
    int root_b = findX(b);
    if(root_a == root_b)
        return;
    if(sz[root_a] < sz[root_b]) {
        bin[root_a] = root_b;
        sz[root_b] += sz[root_a];
        zip(a);
    }
    else {
        bin[root_b] = root_a;
        sz[root_a] += sz[root_b];
        zip(b);
    }
}

int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    init(n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(M[i][j] != 0) {
                merge(i, j);
            }
        }
    }
    set<int> root;
    for(int i = 0; i < n; i++) {
    	int r = findX(i);
        if(root.find(r) == root.end()) {
            root.insert(r);
        }
    }
    return root.size();
}

int main() {
    int n;
    cout << "Please input num: ";
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int val;
            cin >> val;
            M[i][j] = val;
        }
    }
    int res = findCircleNum(M);
    cout << res << endl;
    return 0;
}
