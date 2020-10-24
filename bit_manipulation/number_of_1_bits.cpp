int Solution::numSetBits(unsigned int A) {
    A = (A & 0x55555555) + ((A >> 1) & 0x55555555);
    A = (A & 0x33333333) + ((A >> 2) & 0x33333333);
    A = (A & 0x0F0F0F0F) + ((A >> 4) & 0x0F0F0F0F);
    A = (A & 0x00FF00FF) + ((A >> 8) & 0x00FF00FF);
    A = (A & 0x0000FFFF) + ((A >> 16) & 0x0000FFFF);
    return A;
}
