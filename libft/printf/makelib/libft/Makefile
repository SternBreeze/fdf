NAME = libft.a
SRC = mem/ft_*.c math/*.c str/ft_*.c print/ft_*.c gnl/get_next_line.c \
ADT/stack.c ADT/queue.c ADT/list.c ADT/list2.c
OBJ = *.o
GCCFLAGS = -Wall -Wextra -Werror -g -I ./includes/ -c
.SILENT:
all: $(NAME)
$(NAME): $(SRC)
	gcc $(GCCFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
