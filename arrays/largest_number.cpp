string Solution::largestNumber(const vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end(), [](int a, int b){
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    return accumulate(B.begin(), B.end(), (string)"", [](const string &s, const int a) {
        return s.length() && s[0] == '0' ? to_string(a) : s + to_string(a);
    });
}
