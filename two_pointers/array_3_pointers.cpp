int check(int &ans, int a, int b, int c) {
    int current = max(max(a, b), c) - min(min(a, b), c);
    if (current < ans || ans < 0) {
        ans = current;
    }
}

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int NA = A.size(), NB = B.size(), NC = C.size();
    int a = 0, b = 0, c = 0;
    int ans = -1;
    check(ans, A[a], B[b], C[c]);
    for (a = 0; a < NA; ++a) {
        while (b < NB && B[b] < A[a]) {
            b++;
        }
        while (c < NC && C[c] < A[a]) {
            c++;
        }
        if (b < NB) {
            if (c < NC) {
                check(ans, A[a], B[b], C[c]);
            }
            if (c >= 1) {
                check(ans, A[a], B[b], C[c-1]);
            }
        }
        if (b >= 1) {
            if (c < NC) {
                check(ans, A[a], B[b-1], C[c]);
            }
            if (c >= 1) {
                check(ans, A[a], B[b-1], C[c-1]);
            }
        }
    }
    return ans;
}
