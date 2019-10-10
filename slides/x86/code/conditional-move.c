int 
abs_diff(int x, int y)
{
  int retval = y - x;
  int altval = x - y;
  int xlty = x < y;
  if (xlty) retval = altval;
  return retval;
}

  
