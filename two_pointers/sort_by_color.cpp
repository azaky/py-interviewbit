void Solution::sortColors(vector<int> &A) {
    const int N = A.size();
    // [0, l0) contains 0
    // [l0, l1) contains 1
    // [l1, l2) contains 2
    int l0 = 0, l1 = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == 0) {
            swap(A[l0], A[i]);
            if (l0 < l1) swap(A[i], A[l1]);
            l0++;
            l1++;
        } else if (A[i] == 1) {
            swap(A[l1], A[i]);
            l1++;
        }
    }
}
