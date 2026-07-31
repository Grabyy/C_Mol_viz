
int read_file(char *name, char *arg, int is_stdin);

int main(int argc, char *argv[]) 
{
  if (argc == 2)
  {
    read_file(argv[0], argv[1], 0);
    return 0;
  }
  return 1;
}
