/** Return index of first element in a[n] which is k, < 0 if not found. */
int find(int a[], int n, int k) {
  for (int i = 0; i < n; i++) {
    if (a[i] == k) return i;
  }
  return -1;
}
