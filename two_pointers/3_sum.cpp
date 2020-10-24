int Solution::threeSumClosest(vector<int> &A, int B) {
    int size = A.size();
    sort(A.begin(), A.end());
    long long best = 0xFFFFFFFFFFLL;
    for (int i = 0; i + 2 < size; ++i) {
        if ((long long)A[i] + A[i + 1] + A[i + 2] - B > abs(best - B)) {
            break;
        }
        int k = size - 1;
        for (int j = i + 1; j + 1 < size; ++j) {
            while (k > j && (long long)A[i] + A[j] + A[k] > B) {
                k--;
            }
            if (k == j) {
                break;
            }
            long long currentSum = (long long) A[i] + A[j] + A[k];
            if ((long long)B - currentSum < abs(best - B)) {
                best = currentSum;
            }
            if (k + 1 < size) {
                currentSum = (long long) A[i] + A[j] + A[k + 1];
                if (abs(currentSum - B) < abs(best - B)) {
                    best = currentSum;
                }
            }
        }
    }
    return (int)best;
}
