string Solution::multiply(string A, string B) {
    int NA = A.size(), NB = B.size();
    vector<int> res(NA + NB, 0);
    for (int i = 0; i < NA; ++i) {
        for (int j = 0; j < NB; ++j) {
            res[i+j] += (A[NA-1-i]-'0')*(B[NB-1-j]-'0');
        }
    }
    for (int i = 0; i+1 < NA+NB; ++i) {
        res[i+1] += res[i] / 10;
        res[i] %= 10;
    }
    int len = NA+NB;
    while (len > 0 && res[len-1] == 0) {
        len--;
    }
    if (len == 0) {
        len++;
    }
    string ans(len, '0');
    for (int i = 0; i < len; ++i) {
        ans[len-1-i] = '0' + res[i];
    }
    return ans;
}
