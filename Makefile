FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
DEBUG=-ggdb3
NAME=fdf
SRC=*.c
INCLUDES=libft/libft.a mlx/libmlx.a

all:
	@make -C libft/ all
	@make -C mlx/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS) $(DEBUG)

clean:
	@make -C libft/ clean
	@make -C mlx/ clean

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all