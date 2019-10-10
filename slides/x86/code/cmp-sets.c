int 
f(int x, int y, unsigned a, unsigned b)
{
  int xlty = x < y;
  int ageb = a >= b;
  int aeq0 = (a == 0);
  return xlty + ageb + aeq0;
}
