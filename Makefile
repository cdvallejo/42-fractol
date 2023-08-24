# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 09:58:38 by cvallejo          #+#    #+#              #
#    Updated: 2023/08/22 15:52:07 by cvallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus
SRCS = src/main.c src/fractol.c src/graphics.c src/colors.c src/hooks.c src/utils.c src/mandelbrot.c src/julia.c
SRCS_BONUS = src_bonus/main_bonus.c src_bonus/fractol_bonus.c src_bonus/graphics_bonus.c src_bonus/colors_bonus.c src_bonus/hooks_bonus.c src_bonus/utils_bonus.c src_bonus/mandelbrot_bonus.c src_bonus/julia_bonus.c src_bonus/burningship_bonus.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libraries/libft
MLX42 =	./libraries/MLX42
HEADERS	= -I include -I $(MLX42)/include/MLX42
RM = rm -f
LIBRARIES =	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(MLX42)/libmlx42.a $(LIBFT)/libft.a
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all:	$(NAME)
bonus:	$(NAME_BONUS)

$(NAME):	$(OBJS)
			@make -C $(MLX42)
			@make -C $(LIBFT) --silent
			$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBRARIES) -o $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS)
			@make -C $(MLX42)
			@make -C $(LIBFT) --silent
			$(CC) $(CFLAGS) $(OBJS_BONUS) $(HEADERS) $(LIBRARIES) -o $(NAME_BONUS)

clean:
			@make -C $(MLX42) clean
			@make -C $(LIBFT) clean --silent
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:
		@make -C $(MLX42) clean
		@make -C $(LIBFT) fclean --silent
		$(RM) $(OBJS) $(NAME) $(OBJS_BONUS) $(NAME_BONUS)

re:		fclean all

run:	all bonus
		./$(NAME)

.PHONY:	all clean fclean re bonus