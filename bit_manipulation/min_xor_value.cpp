int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int minxor = A[0] ^ A[1];
    for (int i = 1; i < A.size(); ++i) {
        minxor = min(minxor, A[i] ^ A[i-1]);
    }
    return minxor;
}
/*
 101100
  11011
  10011
  10001
*/