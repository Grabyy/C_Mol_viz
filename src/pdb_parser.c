#include "pdb_parser.h"

void ft_print_str(char *s1, int fd) 
{
  while (*s1) {
    write(fd, s1, 1);
    s1++;
  }
}

int ft_is_atom(char *buffer) 
{
  char *atom = "ATOM";
  int i;

  i = 0;
  while (buffer[i] == atom[i]) {
    i++;
  }
  if (i == 4)
    return 1;
  return 0;
}

void ft_print_error(char *name, char *s) 
{
  ft_print_str(basename(name), 2);
  ft_print_str(": ", 2);
  ft_print_str(s, 2);
  ft_print_str(": ", 2);
  ft_print_str(strerror(errno), 2);
  ft_print_str("\n", 2);
}

int read_file(char *name, char *arg, int *tab_size, atom ***atom_tab) 
{
  int fd;
  char buffer[81];
  ssize_t sread;
  atom **tmp;

  fd = open(arg, O_RDONLY);
  if (fd == -1) {
    ft_print_error(name, arg);
    return (-1);
  }
  sread = 1;
  while (sread) {
    sread = read(fd, buffer, 81);
    if (sread == -1) {
      ft_print_error(name, arg);
      close(fd);
      return (-1);
    }
    if (ft_is_atom(buffer))
    {
      tmp = add_new_atom(*atom_tab, tab_size, buffer);
      if (!tmp)
        return (-1);
      *atom_tab = tmp;
      tmp = NULL;
    }
  }
  close(fd);
  return (0);
}
