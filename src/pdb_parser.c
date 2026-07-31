#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

void ft_print_str(char *s1, int fd) {
  while (*s1) {
    write(fd, s1, 1);
    s1++;
  }
}

int ft_is_atom(char *buffer) {
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

void ft_print_error(char *name, char *s) {
  ft_print_str(basename(name), 2);
  ft_print_str(": ", 2);
  ft_print_str(s, 2);
  ft_print_str(": ", 2);
  ft_print_str(strerror(errno), 2);
  ft_print_str("\n", 2);
}

int read_file(char *name, char *arg, int is_stdin) {
  int fd;
  char buffer[80];
  ssize_t sread;

  fd = 0;
  if (!is_stdin)
    fd = open(arg, O_RDONLY);
  if (fd == -1) {
    ft_print_error(name, arg);
    return (-1);
  }
  sread = 1;
  while (sread) {
    sread = read(fd, buffer, 80);
    if (sread == -1) {
      ft_print_error(name, arg);
      close(fd);
      return (-1);
    }
    if (ft_is_atom(buffer))
      write(1, buffer, sread);
  }
  close(fd);
  return (0);
}
