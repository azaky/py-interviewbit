int Solution::repeatedNumber(const vector<int> &A) {
    int N = A.size();
    int attempts = 20; // there's (2/3)^20 = 0.0003007 chance that we fail find such number, if exists

    // manual work for small sizes
    if (N < attempts) {
        for (int i = 0; i < N; ++i) {
            int occ = 0;
            for (int j = 0; j < N; ++j) {
                if (A[i] == A[j]) {
                    occ++;
                }
            }
            if (occ * 3 > N) {
                return A[i];
            }
        }
        return -1;
    }
    
    while (attempts--) {
        int i = rand() % N;
        int occ = 0;
        for (int j = 0; j < N; ++j) {
            if (A[i] == A[j]) {
                occ++;
            }
        }
        if (occ * 3 > N) {
            return A[i];
        }
    }
    return -1;
}
