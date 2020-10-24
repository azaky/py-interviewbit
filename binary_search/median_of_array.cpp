int find(const vector<int> &A, const vector<int> &B, int k) {
  int i_a = 0, j_a = A.size()-1;
  int i_b = 0, j_b = B.size()-1;
  
  // condition stop: A size is 0 or B size is 0
  int it = 0;
  while (not ((j_a < i_a) or (j_b < i_b))) { // shouldn't it be i_a <= j_a
    int mid_val = A[(i_a+j_a+1)/2];
    
    int lower_idx_mid_val = (i_a + j_a + 1) / 2;

    int lower_idx_mid_val_in_b = -1;
    int l = i_b, r = j_b;
    while (l < r) {
      int mid = (l+r) >> 1;
      if (B[mid] < mid_val)
        l = mid+1;
      else
        r = mid;
    }
    if (B[l] < mid_val) // this usual happens when the index pass the size of array
      l++;
    lower_idx_mid_val_in_b = l;
    
    int number_less_than_mid_val = (lower_idx_mid_val-i_a)+(lower_idx_mid_val_in_b-i_b);
    if (number_less_than_mid_val < k) {
      i_a = lower_idx_mid_val;
      i_b = lower_idx_mid_val_in_b;
      k -= number_less_than_mid_val;
      if (number_less_than_mid_val == 0) { // A[i_a] <= B[i_b]
        if (k == 1)
          return A[i_a];
        else
          return B[i_b + k - 2]; // (k-1)th element in B
      }
    } else {
      j_a = lower_idx_mid_val-1;
      j_b = lower_idx_mid_val_in_b-1;
    }
  }
  
  // reach here when one of the array is reduced to size 0
  if (j_a < i_a)
    return B[i_b+k-1];
  return A[i_a+k-1];
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
  int length = A.size()+B.size();
  if (length%2) {
    return find(A, B, length/2+length%2);
  }
  int mid_left = find(A, B, length/2);
  int mid_right = find(A, B, length/2+1);
  return ((double)(mid_left+mid_right)/2);
}
