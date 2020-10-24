int Solution::maxArea(vector<int> &A) {
    int N = A.size();
    int l = 0, r = N - 1;
    int ans = min(A[l], A[r]) * (N-1);
    while (l < r) {
        while (l < r && A[r] <= A[l]) {
            r--;
            ans = max(ans, min(A[l], A[r]) * (r - l));
        }
        while (l < r && A[l] <= A[r]) {
            l++;
            ans = max(ans, min(A[l], A[r]) * (r - l));
        }
    }
    return ans;
}
