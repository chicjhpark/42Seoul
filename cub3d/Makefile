NAME		= cub3D

CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror
LIBS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS		= main.c

OBJS		= $(SRCS:.c=.o)

%.o		: %.c
		$(CC) $(CFLAGS) -c $<

$(NAME)		: $(OBJS)
		$(CC) $(LIBS) $< -o $@

.PHONY		: all clean fclean re bonus

clean	:
		rm -f $(OBJS)

fclean	: clean
		rm -f $(NAME)

all		: $(NAME)
		./cub3d

re		: fclean all
