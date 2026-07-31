#include <stdlib.h>
#include "./header/atom.h"

// #include <stdio.h>
int main(int argc, char *argv[]) 
{
  int *tab_size;
  atom **atom_tab;

  if (argc == 2)
  {
    tab_size = malloc(sizeof(int));
    *tab_size = 0;
    atom_tab = malloc(sizeof(atom*));
    read_file(argv[0], argv[1], tab_size, atom_tab);
    *tab_size = *tab_size - 1;
    // printf("type : %c x : %f y : %f z : %f\n", atom_tab[0]->type, atom_tab[0]->x, atom_tab[0]->y, atom_tab[0]->z);
    // printf("type : %c x : %f y : %f z : %f\n", atom_tab[*tab_size]->type, atom_tab[*tab_size]->x, atom_tab[*tab_size]->y, atom_tab[*tab_size]->z);
    return 0;
  }
  return 1;
}
