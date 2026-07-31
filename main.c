#include <stdlib.h>
#include "./header/atom.h"

int main(int argc, char *argv[]) 
{
  int *tab_size;
  atom **atom_tab;

  if (argc == 2)
  {
    tab_size = malloc(sizeof(int));
    *tab_size = 0;
    atom_tab = 0;

    read_file(argv[0], argv[1], tab_size, atom_tab);
    return 0;
  }
  return 1;
}
