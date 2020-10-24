int Solution::singleNumber(const vector<int> &A) {
    int t[20] = {0};
    for (int a : A) {
        for (int k = 0; a > 0; k++, a /= 3) {
            t[k] = (t[k] + (a % 3)) % 3;
        }
    }
    int ans = 0;
    for (int i = 19; i >= 0; --i) {
        ans *= 3;
        ans += t[i];
    }
    return ans;
}
