# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 14:46:09 by avenzel           #+#    #+#              #
#    Updated: 2017/12/05 20:39:56 by avenzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= fractol.c	burning_ship_set.c	functions1.c	init_par.c	\
		julia_set.c	mandelbrot_set.c	mouse_focus.c	\
		my_newt_ft.c	my_newt_ft2.c	newton_fractal.c	hookfuncs.c	\
		ft_itoa.c	ft_atoi.c	ft_putendl.c

INCDIR	= ./inc
SRCDIR	= ./src
OBJDIR	= ./obj

CC		= gcc -Wall -Wextra -Werror

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

$(NAME)	: obj $(OBJ) $(MLX)
	$(CC) $(OBJ) -o $(NAME) \
		-O3 -L ./minilibx_macos/ -lmlx -lpthread -framework OpenGL -framework AppKit

all		: $(NAME)

obj		:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) -I $(INCDIR) -I ./minilibx_macos -o $@ -c $<

$(MLX)		:
	@make -C minilibx_macos/

lclean	:
	make -C minilibx_macos/ fclean

clean	: lclean
	rm -rf $(OBJDIR)

fclean	: clean
	rm -f $(NAME)

re		: fclean all
