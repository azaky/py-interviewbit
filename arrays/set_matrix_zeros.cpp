void Solution::setZeroes(vector<vector<int> > &A) {
    int r = A.size();
    if (r == 0) return;
    int c = A[0].size();
    bool hasZeroR = false;
    bool hasZeroC = false;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (A[i][j] == 0) {
                if (i == 0) {
                    hasZeroR = true;
                }
                if (j == 0) {
                    hasZeroC = true;
                }
                A[i][0] = A[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < r; ++i) {
        for (int j = 1; j < c; ++j) {
            if (A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }
    if (hasZeroR) {
        for (int i = 0; i < c; ++i) {
            A[0][i] = 0;
        }
    }
    if (hasZeroC) {
        for (int i = 0; i < r; ++i) {
            A[i][0] = 0;
        }
    }
}
