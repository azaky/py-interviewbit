/* assuming p is an odd number greater than 1 */
bool isPrime(int p) {
    if (p < 9) return true;
    for (int i = 3; i * i <= p; i += 2) {
        if (p % i == 0) return false;
    }
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> result(2);
    if (A == 4) {
        result[0] = result[1] = 2;
    } else {
        for (int p = 3, q = A - 3; p < q; p += 2, q -= 2) {
            if (isPrime(p) && isPrime(q)) {
                result[0] = p;
                result[1] = q;
                break;
            }
        }
    }
    return result;
}
