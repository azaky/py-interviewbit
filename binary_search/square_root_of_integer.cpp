int Solution::sqrt(int A) {
    long long l = 0, r = A;
    while (l < r) {
        long long m = (l + r) >> 1LL;
        long long mSquare = m * m;
        long long mPlus1Square = (m + 1) * (m + 1);
        if (A < mSquare) {
            r = m - 1;
        } else if (mSquare <= A && A < mPlus1Square) {
            return m;
        } else {
            l = m + 1;
        }
    }
    return l;
}
