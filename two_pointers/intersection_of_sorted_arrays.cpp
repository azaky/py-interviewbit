vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;
    int pA = 0, pB = 0;
    int sizeA = A.size(), sizeB = B.size();
    while (pA < sizeA) {
        while (pB < sizeB && B[pB] < A[pA]) {
            pB++;
        }
        if (pB < sizeB && B[pB] == A[pA]) {
            ans.push_back(B[pB++]);
        }
        pA++;
    }
    return ans;
}
