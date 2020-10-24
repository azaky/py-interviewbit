int Solution::singleNumber(const vector<int> &A) {
    int x = 0;
    for (int a : A) x ^= a;
    return x;
}
