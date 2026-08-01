#ifndef ATOM_H
#define ATOM_H

typedef struct satom 
{
  char  type;
  float x;
  float y;
  float z;
} atom;

int read_file(char *name, char *arg, int *tab_size, atom ***atom_tab);
atom **add_new_atom(atom **atom_tab, int *tab_size, char *buffer);
void clean_tab(atom **atom_tab, int *tab_size);
float ft_atoi(char *s);

#endif
