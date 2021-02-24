#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct  s_tag
{
    va_list ap;
    char    *fmt;
    char    *str;
    int     minus;
    int     zero;
    int     width;
    int     prec;
    int     size;
    int     dot;
    int     res;
    int     nbr;
    int     lspace;
    int     rspace;
}               f_tag;

void    init_tag(f_tag *tag)
{
    tag->minus = 0;
    tag->zero = 0;
    tag->width = 0;
    tag->prec = 0;
    tag->size = 0;
    tag->dot = 0;
    tag->lspace = 0;
    tag->rspace = 0;
}

int     ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int     ft_putstr(char *s)
{
    int res;

    res = 0;
    if (s == NULL)
        return (0);
    while (*s != '\0')
    {
        write(1, &*s++, 1);
        res++;
    }
    return (res);
}

int     ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (c);
    return (0);
}

int     strchr_spec(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
        c == 'i' || c == 'u' || c == 'x' || c == 'X')
        return (1);
    return (0);
}

char    *ft_itoa_sign(f_tag *tag)
{
    char    *s;

    if (!(s = (char *)malloc(sizeof(char) * (tag->size + 1))))
        return (NULL);
    s[tag->size] = '\0';
    if (tag->nbr < 0)
        while (tag->size-- > 0)
        {
            s[tag->size] = ((tag->nbr % 10) * -1) + '0';
            tag->nbr /= 10;
        }
    if (tag->nbr >= 0)
        while (tag->size-- > 0)
        {
            s[tag->size] = (tag->nbr % 10) + '0';
            tag->nbr /= 10;
        }
    return (s);
}

void     digits_size(f_tag *tag)
{
    int n;

    n = tag->nbr;
    tag->size = 1;
    if (n < 0)
        while (n <= -10)
        {
            n /= -10;
            tag->size++;
        }
    if (n >= 0)
        while (n >= 10)
        {
            n /= 10;
            tag->size++;
        }
}

void    sort_width_prec(f_tag *tag)
{
    if (*tag->fmt == '.')
        tag->dot = 1;
    else if (*tag->fmt == '*')
    {
        if (tag->dot == 1)
            tag->prec = va_arg(tag->ap, int);
        else
            tag->width = va_arg(tag->ap, int);
    }
    else if (ft_isdigit(*tag->fmt) != 0)
    {
        if (tag->dot == 1)
            tag->prec = (tag->prec * 10) + *tag->fmt - '0';
        else
            tag->width = (tag->width * 10) + *tag->fmt - '0';
    }
}

void    print_di(f_tag *tag)
{
    digits_size(tag);
    if (tag->nbr < 0)
    {
        tag->lspace -= 1;
        tag->rspace -= 1;
    }
    while (tag->lspace-- > 0)
        tag->res += ft_putchar(' ');
    if (tag->nbr < 0)
        tag->res += ft_putchar('-');
    while (tag->zero-- > 0)
        tag->res += ft_putchar('0');
    while (tag->prec-- > 0)
        tag->res += ft_putchar('0');
    if (tag->nbr == 0 && tag->dot == 0)
        tag->res += ft_putchar('0');
    else if (tag->nbr > 0 || tag->nbr < 0)
        tag->res += ft_putstr(ft_itoa_sign(tag));
    while (tag->rspace-- > 0)
        tag->res += ft_putchar(' ');
}

void    sort_spec(f_tag *tag)
{
    if (*tag->fmt == 'd' || *tag->fmt == 'i')
        print_di(tag);
}

void    check_tag(f_tag *tag)
{
    if (*tag->fmt == '-')
        tag->minus = 1;
    else if (*tag->fmt == '0' && tag->width == 0 && tag->dot == 0)
        tag->zero = 1;
    else if (*tag->fmt == '*' || *tag->fmt == '.' || ft_isdigit(*tag->fmt) != 0)
        sort_width_prec(tag);
    else if (tag->zero != 0 && tag->minus == 1)
        tag->zero = 0;
}

void    sort_tag(f_tag *tag)
{
    if (tag->prec > tag->width && tag->prec > tag->size)
        tag->prec -= tag->size;
    else if (tag->width > tag->prec && tag->width > tag->size)
    {
        if (tag->prec > tag->size)
        {
            if (tag->minus == 1)
                tag->rspace = tag->width - tag->prec;
            else if (tag->zero == 1)
                tag->zero = tag->width - tag->prec;
            else
                tag->lspace = tag->width - tag->prec;
            tag->prec -= tag->size;
        }
        else
        {
            if (tag->minus == 1)
                tag->rspace = tag->width - tag->size;
            else if (tag->zero == 1)
                tag->zero = tag->width - tag->size;
            else
                tag->lspace = tag->width - tag->size;
            tag->prec = 0;
        }
    }
}

void    check_type(f_tag *tag)
{
    if (*tag->fmt == 'd' || *tag->fmt == 'i')
    {
        tag->nbr = va_arg(tag->ap, int);
        digits_size(tag);
    }
}
void    sort_format(f_tag *tag)
{
    tag->res = 0;
    while (*tag->fmt != '\0')
    {
        while (*tag->fmt != '%' && *tag->fmt != '\0')
            tag->res += ft_putchar(*tag->fmt++);
        if (*tag->fmt == '%')
        {
            init_tag(tag);
            while (*++tag->fmt != '\0' && strchr_spec(*tag->fmt) == 0)
                check_tag(tag);
            if (strchr_spec(*tag->fmt) != 0)
            {
                check_type(tag);
                sort_tag(tag);
                sort_spec(tag);
            }
            tag->fmt++;
        }
    }
}

int     ft_printf(const char *format, ...)
{
    f_tag   tag;

    if (format == NULL)
        return (-1);
    va_start(tag.ap, format);
    tag.fmt = (char *)format;
    sort_format(&tag);
    va_end(tag.ap);
    return (tag.res);
}

int     main(void)
{
    ft_printf("imt : %.0d\n", 0);
    printf("org : %.0d\n", 0);
    ft_printf("imt : %-10.5d\n", -216);
    printf("org : %-10.5d\n", -216);
    ft_printf("imt : %-3.7d\n", -2375);
    printf("org : %-3.7d\n", -2375);
    ft_printf("imt : %010.5d\n", -216);
    //printf("org : %010.5d\n", -216);
    ft_printf("imt : %08.3d\n", -8473);
    //printf("org : %08.3d\n", -8473);
    ft_printf("imt : %4i\n", -2464);
    printf("org : %4i\n", -2464);
    ft_printf("imt : %-7i\n", -14);
    printf("org : %-7i\n", -14);
    ft_printf("imt : %-3i\n", 0);
    printf("org : %-3i\n", 0);
    ft_printf("imt : %-5i\n", -2562);
    printf("org : %-5i\n", -2562);
    ft_printf("imt : %-4i\n", -2464);
    printf("org : %-4i\n", -2464);

    return (0);
}