// const int INT_MAX = 0x7FFFFFFF;
// const int INT_MIN = 0x80000000;

int Solution::divide(int AA, int BB) {
    long A = AA, B = BB;
    // the only overflow case that may happen
    if (A == INT_MIN) {
        if (B == -1) return INT_MAX;
        if (B == 1) return INT_MIN;
    }
    int sgn = ((A > 0) ^ (B > 0)) ? -1 : 1;
    if (A < 0) {
        A = -A;
    }
    if (B < 0) {
        B = -B;
    }
    long ans = 0;
    for (long i = 31; i >= 0; --i) {
        if (A >= (B << i)) {
            ans ^= 1LL << i;
            A -= (B << i);
        }
    }
    if (sgn < 0) {
        ans = -ans;
    }
    if (ans > INT_MAX) {
        ans = INT_MAX;
    }
    return ans;
}
