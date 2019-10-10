int g(int *a, int n);

int f(int n) {
  int m = 2*n + 1;
  int a[m];
  for (int i = 0; i < m; i++) {
    a[i] = i;
  }
  return g(a, m);
}
