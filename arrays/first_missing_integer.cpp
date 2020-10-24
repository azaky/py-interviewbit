int Solution::firstMissingPositive(vector<int> &A) {
    int size = A.size();
    for (int i = 0; i < size; ++i) {
        while (0 < A[i] && A[i] <= size) {
            if (A[A[i] - 1] == A[i]) break;
            swap(A[i], A[A[i] - 1]);
        }
    }
    for (int i = 0; i < size; ++i) {
        if (A[i] != i + 1) {
            return i + 1;
        }
    }
    return size + 1;
}
