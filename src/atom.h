#ifndef ATOM_H
#define ATOM_H

#include <stdlib.h>
#include "utils.h"

typedef struct satom 
{
  char  type;
  float x;
  float y;
  float z;
} atom;

atom **add_new_atom(atom **atom_tab, int *tab_size, char *buffer);
void clean_tab(atom **atom_tab, int *tab_size);

#endif
