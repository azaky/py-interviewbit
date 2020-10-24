unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    for (unsigned int l = 0, r = 31; l < r; l++, r--) {
        unsigned int temp = (A & ((unsigned int)1 << l)) >> l;
        A &= A ^ ((unsigned int)1 << l);
        A ^= ((A & ((unsigned int)1 << r)) >> r) << l;
        A &= A ^ ((unsigned int)1 << r);
        A ^= temp << r;
    }
    return A;
}
