int dp[55][55][55];
string A, B;

int check(int la, int ra, int lb, int rb) {
    if (ra - la != rb - lb) return 0;
    if (ra - la == 1) {
        return A[la] == B[lb];
    }
    if (dp[la][lb][ra - la]) {
        return dp[la][lb][ra - la] - 1;
    }
    for (int len = 1; len < ra - la; ++len) {
        if (
            (check(la, la + len, lb, lb + len) && check(la + len, ra, lb + len, rb)) ||
            (check(la, la + len, rb - len, rb) && check(la + len, ra, lb, rb - len))
        ) {
            dp[la][lb][ra - la] = 2;
            return 1;
        }
    }
    dp[la][lb][ra - la] = 1;
    return 0;
}

int Solution::isScramble(const string _A, const string _B) {
    A = _A; B = _B;
    for (int i = 0; i < 55; ++i) {
        for (int j = 0; j < 55; ++j) {
            for (int k = 0; k < 55; ++k) {
                dp[i][j][k] = 0;
            }
        }
    }
    return check(0, A.size(), 0, B.size());
}
