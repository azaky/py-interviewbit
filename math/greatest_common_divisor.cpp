int Solution::gcd(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A == 0 || B == 0) {
        return A + B;
    } else {
        return gcd(B, A % B);
    }
}
