int 
move(int *ip, unsigned char *cp)
{
  unsigned short s1 = *ip;
  unsigned short s2 = *cp;
  unsigned short t = s1 + s2;
  return t;
}
