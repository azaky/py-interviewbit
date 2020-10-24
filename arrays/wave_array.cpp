vector<int> Solution::wave(vector<int> &A) {
    int size = A.size();
    vector<int> ans(size);
    sort(A.begin(), A.end());
    for (int i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            ans[i] = A[i + 1];
            ans[i + 1] = A[i];
        } else {
            ans[i] = A[i];
        }
    }
    return ans;
}
