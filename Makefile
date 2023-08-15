# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 09:58:38 by cvallejo          #+#    #+#              #
#    Updated: 2023/08/15 13:50:05 by cvallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = src/main.c src/fractol.c src/graphics.c src/colors.c src/hooks.c src/utils.c src/mandelbrot.c src/julia.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libraries/libft
MLX42 =	./libraries/MLX42
HEADERS	= -I include -I $(MLX42)/include/MLX42
RM = rm -f
LIBRARIES =	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(MLX42)/libmlx42.a $(LIBFT)/libft.a
OBJS = ${SRCS:.c=.o}

all:	$(NAME)

$(NAME):	$(OBJS)
			@make -C $(MLX42)
			@make -C $(LIBFT) --silent
			$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBRARIES) -o $(NAME)

clean:
			@make -C $(MLX42) clean
			@make -C $(LIBFT) clean --silent
			$(RM) $(OBJS)

fclean:
		@make -C $(MLX42) clean
		@make -C $(LIBFT) fclean --silent
		$(RM) $(OBJS) $(NAME)

re:		fclean all

run:	all
		./$(NAME)

.PHONY:	all clean fclean re