CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -fPIC

LDFLAGS = -ldl -pthread -lm

INCLUDES = -Ilib/LIBFT -Ilib

SRCDIR = src
LIBDIR = lib
LIBFTDIR = $(LIBDIR)/LIBFT

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:.c=.o)

EXECUTABLE = myprogram

all: libft $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ -L$(LIBFTDIR) -lft $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -f $(SRCDIR)/*.o
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(EXECUTABLE)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all libft clean fclean re
