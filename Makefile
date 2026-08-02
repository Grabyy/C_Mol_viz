
CC = cc
CFLAGS = -Wall -Werror -Wextra
SOURCES = src/main.c src/pdb_parser.c src/utils.c src/atom.c
OBJECTS_DIR = object
OBJECTS = $(SOURCES:%.c=$(OBJECTS_DIR)/%.o)
TARGET = C_mol_viz

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(OBJECTS_DIR)/%.o:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

debug: fclean
	$(MAKE) CFLAGS="-Wall -Werror -Wextra -g"

compile: fclean
	$(MAKE) CFLAGS=""

clean: 
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: clean fclean all debug compile
