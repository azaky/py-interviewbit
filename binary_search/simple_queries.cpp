vector<int> Solution::solve(vector<int> &A, vector<int> &Q) {
    const int N = A.size();
    // find r bound
    vector<int> rbound(N);
    vector<pair<int, int> > rstack; // <value, index>
    for (int i = 0; i < N; ++i) {
        while (rstack.size() > 0 && rstack.back().first <= A[i]) {
            rbound[rstack.back().second] = i - 1;
            rstack.pop_back();
        }
        rstack.emplace_back(A[i], i);
    }
    while (!rstack.empty()) {
        rbound[rstack.back().second] = N-1;
        rstack.pop_back();
    }
    // find l bound
    vector<int> lbound(N);
    vector<pair<int, int> > lstack; // <value, index>
    for (int i = N-1; i >= 0; --i) {
        while (lstack.size() > 0 && lstack.back().first < A[i]) {
            lbound[lstack.back().second] = i + 1;
            lstack.pop_back();
        }
        lstack.emplace_back(A[i], i);
    }
    while (!lstack.empty()) {
        lbound[lstack.back().second] = 0;
        lstack.pop_back();
    }
    // finds occurrence of each numbers in the resulting array
    vector<long> occ(N);
    for (int i = 0; i < N; ++i) {
        occ[i] = (long)(i - lbound[i] + 1) * (rbound[i] - i + 1);
    }
    // calculate values in G
    vector<pair<int, int> > G(N);
    for (int i = 0; i < N; ++i) {
        long v = 1;
        for (int d = 1; d * d <= A[i]; ++d) {
            if (A[i] % d == 0) {
                v *= d;
                v %= 1000000007;
                if (d * d != A[i]) {
                    v *= A[i] / d;
                    v %= 1000000007;
                }
            }
        }
        G[i] = make_pair((int)v, i);
    }
    sort(G.begin(), G.end());
    reverse(G.begin(), G.end());
    // calculate cumulative count
    vector<long> cum(N);
    cum[0] = occ[G[0].second];
    for (int i = 1; i < N; ++i) {
        cum[i] = cum[i-1] + occ[G[i].second];
    }
    // answer each queries with binary search
    vector<int> answer;
    for (int q : Q) {
        int l = 0, r = N-1;
        while (l < r) {
            int m = (l + r) / 2;
            if (q <= cum[m]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        answer.push_back(G[l].first);
    }

    return answer;
}
