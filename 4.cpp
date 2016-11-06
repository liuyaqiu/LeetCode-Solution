class Solution {
public:
    int find_kth(vector<int>::iterator iterA, int m, vector<int>::iterator iterB, int n, int k) {
        if(m > n)
            return find_kth(iterB, n, iterA, m, k);
        if(m == 0)
            return *(iterB + k - 1);
        if(k == 1)
            return min(*iterA, *iterB);
        int pa = min(k / 2, m);
        int pb = k - pa;
        if(*(iterA + pa - 1) < *(iterB + pb - 1))
            return find_kth(iterA + pa, m - pa, iterB, n, k - pa);
        else
            return find_kth(iterA, m, iterB + pb, n - pb, k - pb);
    }

    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        int m = A.size(), n = B.size();
        int total = m + n;
        if(total % 2 == 1)
            return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
        else
            return (find_kth(A.begin(), m, B.begin(), n, total / 2) + find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
    }
};

