int Solution::cntBits(vector<int> &A) {
    int b[32] = {0};
    for (int a : A) {
        for (int k = 0; a > 0; k++, a >>= 1) {
            b[k] += a & 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
        ans = (int)(((long)b[i] * (A.size() - b[i]) * 2 + ans) % 1000000007L);
    }
    return ans;
}
