int Solution::titleToNumber(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int p = 1;
    int pp = 0;
    int n = A.length();
    for (int i = 0; i < n; ++i) {
        pp += p;
        p *= 26;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans *= 26;
        ans += (A[i] - 'A');
    }
    ans += pp;
    return ans;
}
