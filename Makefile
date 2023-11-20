# Main Makefile for mylibrary project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -fPIC

# Additional libraries and flags for main.c
LDFLAGS = -ldl -lglfw -pthread -lm
LIBS = libmlx42.a
INCLUDES = -Iinclude

# Directories
SRCDIR = src
LIBDIR = lib
LIBFTDIR = $(LIBDIR)/LIBFT

# Source and object files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:.c=.o)

# Name of the final executable
EXECUTABLE = myprogram

# Main.c specific executable
MAIN_EXECUTABLE = main

# Default target
all: libft $(EXECUTABLE) $(MAIN_EXECUTABLE)

# Compile the main program
$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFTDIR) -lft

# Compile main.c with additional libraries
$(MAIN_EXECUTABLE): main.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIBS) $(LDFLAGS)

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
	rm -f $(EXECUTABLE) $(MAIN_EXECUTABLE)
	$(MAKE) -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all libft clean fclean re
