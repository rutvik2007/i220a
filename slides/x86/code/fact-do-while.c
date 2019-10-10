int 
fact(int n) 
{
  int f = 1;
  int i = 1;
  do {
    f *= i;
    i += 1;
  } while (i < n);
  return f;
}
