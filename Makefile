CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC

LDFLAGS = -ldl -pthread -lm -L$(MINILIBXDIR) -lmlx -lXext -lX11

INCLUDES = -Ilib/LIBFT -Ilib -I$(MINILIBXDIR)

SRCDIR = src
SUBDIRS = bresenham colors controls map_reader menu utils main
LIBDIR = lib
LIBFTDIR = $(LIBDIR)/LIBFT
MINILIBXDIR = $(LIBDIR)/minilibx-linux

SRC = $(wildcard $(SRCDIR)/*.c) \
	$(foreach dir, $(SUBDIRS), $(wildcard $(SRCDIR)/$(dir)/*.c))
OBJ = $(SRC:.c=.o)

EXECUTABLE = myprogram

all: libft minilibx $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ -L$(LIBFTDIR) -lft $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	$(MAKE) -C $(LIBFTDIR)

minilibx:
	$(MAKE) -C $(MINILIBXDIR)

clean:
	rm -f $(SRCDIR)/*.o $(SRCDIR)/*/*.o
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MINILIBXDIR) clean

fclean: clean
	rm -f $(EXECUTABLE)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MINILIBXDIR) clean

re: fclean all

.PHONY: all libft minilibx clean fclean re
