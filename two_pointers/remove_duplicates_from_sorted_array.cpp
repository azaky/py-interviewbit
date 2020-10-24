int Solution::removeDuplicates(vector<int> &A) {
    int size = A.size();
    int pA = 0, pB = 0;
    while (pA < size) {
        while (pA < size && A[pA] == A[pB]) {
            pA++;
        }
        pB++;
        if (pA < size) {
            A[pB] = A[pA];
        }
    }
    A.resize(pB);
    return pB;
}
