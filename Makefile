# Main Makefile for mylibrary project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilib -fPIC

# Directories
SRCDIR = src
LIBDIR = lib
LIBFTDIR = $(LIBDIR)/LIBFT

# Source and object files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:.c=.o)

# Name of the final executable
EXECUTABLE = myprogram

# Default target
all: libft $(EXECUTABLE)

# Compile the main program
$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFTDIR) -lft

# Rule to make objects
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to make libft
libft:
	$(MAKE) -C $(LIBFTDIR)

# Clean objects in main and libft
clean:
	rm -f $(SRCDIR)/*.o
	$(MAKE) -C $(LIBFTDIR) clean

# Full clean (objects and executables)
fclean: clean
	rm -f $(EXECUTABLE)
	$(MAKE) -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all libft clean fclean re
