int rfact(int n) {
  return (n <= 1) ? 1 : n * rfact(n - 1);
}
