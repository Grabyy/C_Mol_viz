#include <stdlib.h>
#include "../header/atom.h"

float ft_atoi(char *s);

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

int add_space(atom *a_tab[], int size)
{
  a_tab = realloc(a_tab, (sizeof(*a_tab) + sizeof(atom)));
  if (!a_tab)
    return -1;
  return size++;
}

float get_coord(int pos, char *buffer)
{
  char tmp[8];
  int i;

  while (i < 8)
  {
    tmp[i] = buffer[pos + i];
    i++;
  }
  return ft_atoi(tmp);
}

int add_new_atom(atom *atom_tab[], int size, char *buffer)
{
  size = add_space(atom_tab, size);
  if (size == -1)
    return size;
  atom_tab[size] = create_atom(buffer[13], 
                              get_coord(31, buffer), 
                              get_coord(39, buffer),
                              get_coord(47, buffer));
  return size;
}

void clean_tab(atom *atom_tab[], int size)
{
  while (size)
  {
    free(atom_tab[size-1]);
    size--;
  }
  free(atom_tab);
}
