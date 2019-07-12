NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g -I libft/includes/
SRC =  printf.c flags.c char.c int.c print_int.c float.c float2.c float_adjust.c spec.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
LIBFTOBJ = libft/*.o
all: $(NAME)
$(OBJ): $(SRC)
	make -C libft
	gcc -c $(SRC) $(CFLAGS)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFTOBJ)
	ranlib $(NAME)
clean:
	/bin/rm -rf $(OBJ)
	make -C libft clean
fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean
re: fclean all
