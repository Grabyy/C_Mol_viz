int check_str(char c)
{
  if ((c >= '0' && c <= '9') || c == '-')
    return 0;
  return 1;
}

int power_pos(int nb, int pow)
{
  int res;

  res = 1;
  while (pow)
  {
    res *= nb;
    pow--;
  }
  return res;
}

float power_min(int nb, int pow)
{
  float res;

  res = nb;
  while (pow)
  {
    res *= 0.1;
    pow--;
  }
  return res;
}

float ft_atoi(char *s)
{
  int pos;
  int minus;
  int pow;
  float res;

  pos = 0;
  minus = 0;
  res = 0;
  while (s[pos] && (check_str(s[pos])))
    pos++;
  if (s[pos] == '-')
  {
    minus++;
    pos++;
  }
  pow = 0;
  while (s[pos+pow] != '.')
    pow++;
  while (s[pos] != '.')
  {
    res += (s[pos] - '0') * power_pos(10, pow - 1);
    pos++;
    pow--;
  }
  pos++;
  pow = 0;
  while (pow < 3)
  {
    pow++;
    res += (s[pos] - '0') * power_min(1, pow);
    pos++;
  }
  if (minus)
    res = -res;
  return res;
}
