# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 08:40:37 by frgutier          #+#    #+#              #
#    Updated: 2022/12/20 09:02:25 by frgutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	 libft.a

CC	=	 gcc

FLAGS	=	 -Werror -Wall -Wextra

AR	=	 ar -rcs

SRC = ft_atoi.c \
		  ft_bzero.c \
	      ft_calloc.c \
		  ft_isalnum.c \
	  	  ft_isalpha.c \
	  	  ft_isascii.c \
	  	  ft_isdigit.c \
	      ft_isprint.c \
	  	  ft_itoa.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_printf.c \
		  print_char.c \
	      print_number.c \
		  print_number_unsigned.c \
		  print_hexa_pointer.c \
		  print_string.c \
		  print_hexa_lower.c \
		  print_hexa_capital.c \
		  aux_functions.c \
		  ft_strlen_f.c \
		  get_next_line.c \
		  get_next_line_utils.c

BONUS	 =	ft_lstnew_bonus.c 	\
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c 

OBJS	 =	$(SRC:%.c=%.o)

OBJ_BONUS=	$(BONUS:%.c=%.o)

all	:	$(NAME)

$(NAME)	: 	$(OBJS) libft.h
	$(AR) $(NAME) $(OBJS)

%.o	:	%.c
	$(CC) $(FLAGS) -c $< -o $@

bonus	:	$(OBJS) $(OBJ_BONUS) libft.h
	$(AR) $(NAME) $(OBJ_BONUS) $(OBJS)

clean	:
	rm -f $(OBJS) $(OBJ_BONUS)

fclean	: 	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY: clean fclean all re bonus
