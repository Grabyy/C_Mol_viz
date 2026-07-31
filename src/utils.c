int check_str(char c)
{
  if (c < '0' || c > '9' || c!= '-')
    return 1;
  return 0;
}

int power_pos(int pow, int nb)
{
  int res;

  if (pow == 0)
    return 1;
  res = nb;
  while (pow)
  {
    res *= nb;
    pow--;
  }
  return res;
}

float power_min(int pow, int nb)
{
  float res;

  if (pow == 0)
    return 1;
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
  while (s[pos] != '.')
  {
    res += s[pos] * power_pos(10, 8 - pos - 1);
    pos++;
  }
  pos++;
  while (pow < 3)
  {
    pow++;
    res += s[pos] * power_min(10, pow);
    pos++;
  }
  return res;
}
