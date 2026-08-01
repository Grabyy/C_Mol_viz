#include <stdlib.h>
#include "../header/atom.h"

atom  *create_atom(char type, float x, float y, float z)
{
  atom  *a;

  a = malloc(sizeof(atom));
  if (!a)
    return NULL;
  a->type = type;
  a->x = x;
  a->y = y;
  a->z = z;

  return a;
}

atom** add_space(atom *a_tab[], int size)
{
  atom **p;
  
  p = realloc(a_tab, ((size + 1) * sizeof(atom*)));
  if (!p)
    return NULL;
  return p;
}

float get_coord(int pos, char *buffer)
{
  char tmp[8];
  int i;

  i = 0;
  while (i < 8)
  {
    tmp[i] = buffer[pos + i];
    i++;
  }
  return ft_atoi(tmp);
}

atom **add_new_atom(atom **atom_tab, int *tab_size, char *buffer)
{
  atom_tab = add_space(atom_tab, *tab_size);
  if (!atom_tab)
    return NULL;
  atom_tab[*tab_size] = create_atom(buffer[13],
                              get_coord(31, buffer),
                              get_coord(39, buffer),
                              get_coord(47, buffer));
  (*tab_size)++;
  return atom_tab;
}

void clean_tab(atom **atom_tab, int *tab_size)
{
  while (*tab_size >= 0)
  {
    free(atom_tab[*tab_size]);
    (*tab_size)--;
  }
  free(atom_tab);
  free(tab_size);
}
