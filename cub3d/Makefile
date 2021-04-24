NAME		= cub3D

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS		= main.c

OBJS		= $(SRCS:.c=.o)

%.o		: %.c
		$(CC) $(CFLAGS) -c -I mlx $< -o $@

$(NAME)		: $(OBJS)
		$(CC) $(INCLUDES) $< -o $@

.PHONY		: all clean fclean re bonus

all		: $(NAME)
		./cub3D

clean		:
		rm -f $(OBJS)

fclean		: clean
		rm -f $(NAME)

re		: fclean all
