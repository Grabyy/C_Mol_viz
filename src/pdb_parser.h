#ifndef PDB_H
#define PDB_H

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

#include "atom.h"

int read_file(char *name, char *arg, int *tab_size, atom ***atom_tab);

#endif 
