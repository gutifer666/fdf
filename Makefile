FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRC= main.c \
		aux_functions.c \
		draw.c \
		init.c \
		keyboard.c \
		read_file.c \
		transformation_functions.c
INCLUDES=libft/libft.a mlx/libmlx.a

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft/ all
		@make -C mlx/ all
		gcc $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(FRAEMWORKS)

%.o: %.c
		gcc $(FLAGS) -c $< -o $@

clean:
	@make -C libft/ clean
	@make -C mlx/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all