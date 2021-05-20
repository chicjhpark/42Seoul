# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 18:51:24 by jaehpark          #+#    #+#              #
#    Updated: 2021/05/19 15:29:25 by jaehpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror

INCS		= -Ilibft -Imlx

SRCS_DIR	= srcs
SRCS_NAME	= cub3d.c \
				get_next_line.c \
				get_next_line_utils.c
				
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS		= $(SRCS:.c=.o)

LIB_DIR		= libft
LIB_NAME	= ft
LIB			= $(addprefix $(LIB_DIR)/, libft.a)

MLX_DIR		= mlx
MLX_NAME	= mlx
MLX			= $(addprefix $(MLX_DIR)/, libmlx.a)

$(NAME)		: $(LIB) $(MLX) $(OBJS)
		$(CC) $(CFLAGS) $(INCS) -Iinclude -L$(LIB_DIR) -l$(LIB_NAME) -L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework AppKit -lz $(OBJS) -o $@

$(LIB)		:
		$(MAKE) -C $(LIB_DIR) bonus

$(MLX)		:
		$(MAKE) -C $(MLX_DIR) all

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -Iinclude -c $< -o $@

all : $(NAME)

clean	:
		$(MAKE) -C $(LIB_DIR) clean
		$(MAKE) -C $(MLX_DIR) clean
		rm -rf $(OBJS)

fclean	:
		$(MAKE) -C $(LIB_DIR) fclean
		$(MAKE) -C $(MLX_DIR) fclean
		rm -rf $(NAME) $(OBJS)

re		: fclean all

bonus	: all

.PHONY	: all clean fclean re bonus
