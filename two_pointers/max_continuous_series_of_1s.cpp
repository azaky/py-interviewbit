vector<int> Solution::maxone(vector<int> &A, int B) {
    int l = 0, r = 0, zeros = A[0] == 0 ? 1 : 0, N = A.size();
    int ansl, ansn = -1;
    while (l <= r && r < N) {
        if (zeros < B) {
            r++;
            if (r < N) {
                if (A[r] == 0) {
                    zeros++;
                }
                if (r - l > ansn) {
                    ansl = l;
                    ansn = r-l;
                }
            }
        } else {
            if (A[l] == 0) {
                zeros--;
            }
            l++;
        }
    }
    vector<int> ans;
    for (int i = 0; i <= ansn; ++i) {
        ans.push_back(ansl + i);
    }
    return ans;
}
