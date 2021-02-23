#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct  s_tag
{
    va_list ap;
    char    *fmt;
    int     minus;
    int     zero;
    int     width;
    int     prec;
    int     size;
    int     res;
}               f_tag;

int		ft_printf(const char *format, ...);

#endif
