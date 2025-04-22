# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enorie <enorie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 12:41:41 by root              #+#    #+#              #
#    Updated: 2024/01/17 15:07:34 by enorie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = gnl/get_next_line_utils.c gnl/get_next_line.c srcs/get_map.c srcs/render.c srcs/error.c \
	srcs/utils.c srcs/utils_pathfinder.c srcs/moves.c srcs/sprite_move.c srcs/pathfinder.c srcs/main.c

CC = cc -Ilibft -Ignl -Imlx_linux -Iincludes -Wall -Wextra -Werror

MLX = mlx_linux/libmlx.a

OBJ = $(SRC:.c=.o)

all: $(NAME)
 
$(NAME): $(MLX) $(OBJ)
	make -C libft
	$(CC) $(OBJ) -Llibft -l:libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(MLX): 
	@if [ ! -d "mlx_linux" ]; then git clone https://github.com/42paris/minilibx-linux.git mlx_linux; fi
	@if [ ! -f "mlx_linux/libmlx.a" ]; then make -C mlx_linux; fi

.c.o:
		$(CC) -c $< -o $(<:.c=.o) 

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	rm -rf mlx_linux

re: fclean all

.PHONY: all clean fclean re
