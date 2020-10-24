int Solution::pow(int x, int n, int d) {
    if (n == 0) {
        return 1 % d;
    } else {
        int temp = pow(((long long)x * x) % (long long)d, n >> 1, d);
        if (n & 1) {
            temp = (int)(((long long)temp * x) % (long long)d);
        }
        temp = (int)(((long long)temp + d) % (long long)d);
        return temp;
    }
}
