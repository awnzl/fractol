# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 14:46:09 by avenzel           #+#    #+#              #
#    Updated: 2017/03/16 19:08:19 by avenzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
LIBFT	= libft/libft.a

SRC		= fractol.c	burning_ship_set.c	functions1.c	init_par.c	\
		 julia_set.c	mandelbrot_set.c	mouse_focus.c	\
		my_newt_ft.c	my_newt_ft2.c	newton_fractal.c	hookfuncs.c 
OBJ		= $(SRC:.c=.o)
CC		= gcc -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT) \
		-O3 -lmlx -lpthread -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -c -o $@ $<

$(LIBFT)	:
	make -C libft/

lclean	:
	make -C libft/ clean
	make -C libft/ fclean

clean	: lclean
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re		: fclean all
