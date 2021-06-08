# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 15:44:16 by jaehpark          #+#    #+#              #
#    Updated: 2021/06/08 20:39:14 by jaehpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror

INCS		= -Ilibft -I.

SRCS_DIR	= ./srcs
SRCS_NAME	= push_swap.c \
				utils.c \
				init.c \
				operation_a.c \
				operation_b.c \
				sort_utils.c
				
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))

OBJS_DIR	= ./objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS_NAME:.c=.o))

LIB_DIR		= libft
LIB_NAME	= ft
LIB			= $(addprefix $(LIB_DIR)/, libft.a)

$(NAME)		: $(LIB) $(OBJS)
		$(CC) $(CFLAGS) $(INCS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS) -o $@

$(LIB)		:
		$(MAKE) -C $(LIB_DIR) bonus

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all 	: $(NAME)
		cp $(NAME) ./tester

clean	:
		$(MAKE) -C $(LIB_DIR) clean
		rm -rf $(OBJS)

fclean	:
		$(MAKE) -C $(LIB_DIR) fclean
		rm -rf $(NAME) $(OBJS)

re		: fclean all

bonus	: all

.PHONY	: all clean fclean re bonus
