NAME		= cub3D

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS		= main.c

OBJS		= $(SRCS:.c=.o)

%.o		: %.c
		$(CC) $(CFLAGS) -c $<

$(NAME)		: $(OBJS)
		$(CC) $(LIBS) $< -o $@

.PHONY		: all clean fclean re bonus

all		: $(NAME)
		./cub3d

clean	:
		rm -f $(OBJS)

fclean	: clean
		rm -f $(NAME)

re		: fclean all
