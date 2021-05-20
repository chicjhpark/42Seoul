# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 18:51:24 by jaehpark          #+#    #+#              #
#    Updated: 2021/05/18 18:24:33 by jaehpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror 
MLX			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lz

SRCS		= main.c

OBJS		= $(SRCS:.c=.o)

%.o		: %.c
		$(CC) $(CFLAGS) -c $<

$(NAME)		: $(OBJS)
		$(CC) $(MLX) $< -o $@

.PHONY		: all clean fclean re bonus

clean	:
		rm -f $(OBJS)

fclean	: clean
		rm -f $(NAME)

all		: $(NAME)
		./cub3d

re		: fclean all
