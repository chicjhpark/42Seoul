# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 12:10:53 by jaehpark          #+#    #+#              #
#    Updated: 2021/07/06 05:57:58 by jaehpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex

CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror

INCS			= -Ilibft -I.

SRCS_DIR		= .
SRCS_NAME		= pipex.c

SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))

OBJS_DIR		= .
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS_NAME:.c=.o))

LIB_DIR			= libft
LIB_NAME		= ft
LIB				= $(addprefix $(LIB_DIR)/, libft.a)

$(NAME)			: $(LIB) $(OBJS)
				$(CC) $(CFLAGS) $(INCS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS) -o $@

$(LIB)			:
				$(MAKE) -C $(LIB_DIR) bonus

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
					mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all 			: $(NAME)

bonus			: $(NAME)

clean			:
					$(MAKE) -C $(LIB_DIR) clean
					rm -rf $(OBJS_DIR)

fclean			:
					$(MAKE) -C $(LIB_DIR) fclean
					rm -rf $(NAME) $(OBJS_DIR)

re				: fclean all

.PHONY			: all clean fclean re bonus