NAME = fdf
CFLAGS = -Wall -Wextra -Werror -g -I libft/includes/
SRC = main.c hooks.c service.c parse.c draw.c print_line.c projection.c menu.c \
image.c priority_draw.c hook_service.c io.c io_service.c map.c menu_hooks.c \
color.c light.c menu_output.c menu_output_service.c print_smooth_line.c \
tetra.c clipper.c clipper_service.c projection_service.c scale.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
PRINTF = libft/libftprintf.a
MLX = mlx/libmlx.a
.SILENT:
all: $(MLX) $(NAME)
$(MLX):
	make -C mlx
$(LIBFT):
	make -C libft
$(OBJ1): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@
$(NAME): $(LIBFT) $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME) -framework Opengl -framework AppKit $(MLX)
clean:
	/bin/rm -rf $(OBJ)
	/bin/rm -rf *.dSYM
	make -C libft clean
	make -C mlx clean
fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean
	make -C mlx fclean
re: fclean all
