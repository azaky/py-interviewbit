int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int r = A.size();
    if (r == 0) return 0;
    int c = A[0].size();
    
    int currentR = r - 1;
    int currentC = 0;
    while (currentC < c && currentR >= 0) {
        if (A[currentR][currentC] == B) {
            return 1;
        } else if (A[currentR][currentC] < B) {
            currentC++;
        } else {
            currentR--;
        }
    }
    return 0;
}
