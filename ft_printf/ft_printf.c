#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

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

int     ft_putchar(char c)
{
    return (write(1, &c, 1));
}

void    init_tag(f_tag *tag)
{
    tag->minus = 0;
    tag->zero = 0;
    tag->width = 0;
    tag->prec = -1;
    tag->size = 0;
}

int     strchr_spec(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
        c == 'i' || c == 'u' || c == 'x' || c == 'X')
        return (1);
    return (0);
}

int     ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (c);
    return (0);
}

void    sort_width_prec(f_tag *tag)
{
    if (*tag->fmt == '.')
    {
		tag->zero = 0;
        if (*++tag->fmt == '*')
            tag->prec = va_arg(tag->ap, int);
		else if (ft_isdigit(*tag->fmt) != 0)
            tag->prec = (tag->prec * 10) + *tag->fmt - '0';
    }
    else if (*tag->fmt == '*')
        tag->width = va_arg(tag->ap, int);
	else if (ft_isdigit(*tag->fmt) != 0)
        tag->width = (tag->width * 10) + *tag->fmt - '0';
}

int     digits_count(int n)
{
    int count;

    count = 1;
    if (n < 0)
        while (n < - 9)
        {
            n /= -10;
            count++;
        }
    if (n >= 0)
        while (n > 9)
        {
            n /= 10;
            count++;
        }
    return (count);
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

char    *ft_itoa_sign(int n)
{
    char    *s;
    int     count;

    count = digits_count(n);
    if (!(s = (char *)malloc(sizeof(char) * (count + 1))))
        return (NULL);
    s[count] = '\0';
    if (n == 0)
        return ("0");
    else if (n < 0)
        while (count--)
        {
            s[count] = ((n % 10) * -1) + '0';
            n /= 10;
        }
    else
        while (count--)
        {
            s[count] = (n % 10) + '0';
            n /= 10;
        }
    return (s);
}

void    largest_prec(f_tag *tag, int di)
{
    int gap;
    
    if (di < 0)
        tag->res += ft_putchar('-');
    gap = tag->prec - tag->size;
    while (gap-- != 0)
        tag->res += ft_putchar('0');
}

void    largest_width_right(f_tag *tag, int di)
{
    int gap;

    if (tag->prec > tag->size)
    {
        gap = tag->width - tag->prec;
        while (gap-- != 0)
            tag->res += ft_putchar(' ');
        if (di < 0)
            tag->res += ft_putchar('-');
        gap = tag->prec - tag->size;
        while (gap-- != 0)
            tag->res += ft_putchar('0');
    }
    else
    {
        gap = tag->width - tag->size;
		if (tag->zero == 1)
		{
			if (di < 0)
				tag->res += ft_putchar('-');
			while (gap-- != 0)
				tag->res += ft_putchar('0');
		}
		else
		{
			while (gap-- != 0)
            	tag->res += ft_putchar(' ');
        	if (di < 0)
            	tag->res += ft_putchar('-');
		}
    }
}

void    largest_width_left(f_tag *tag, int di)
{
    int gap;

    if (di < 0)
        tag->res += ft_putchar('-');
    if (tag->prec > tag->size)
    {
        gap = tag->prec - tag->size;
        while (gap-- != 0)
            tag->res += ft_putchar('0');
        tag->res += ft_putstr(ft_itoa_sign(di));
        gap = tag->width - tag->prec;
        while (gap-- != 0)
            tag->res += ft_putchar(' ');
    }
    else
    {
        tag->res += ft_putstr(ft_itoa_sign(di));
        gap = tag->width - tag->size;
        while (gap-- != 0)
            tag->res += ft_putchar(' ');
    }
}

void    right_sort(f_tag *tag, int di)
{
    if (tag->prec > tag->width && tag->prec > tag->size)
        largest_prec(tag, di);
    else if (tag->width > tag->prec && tag->width > tag->size)
        largest_width_right(tag, di);
    else
        if (di < 0)
            tag->res += ft_putchar('-');
    tag->res += ft_putstr(ft_itoa_sign(di));    
}

void    left_sort(f_tag *tag, int di)
{
    if (tag->prec > tag->width && tag->prec > tag-> size)
    {
        largest_prec(tag, di);
        tag->res += ft_putstr(ft_itoa_sign(di));
    }
    else if (tag->width > tag->prec && tag->width > tag->size)
        largest_width_left(tag, di);
    else
    {
        if (di < 0)
            tag->res += ft_putchar('-');
        tag->res += ft_putstr(ft_itoa_sign(di));
    }
}

void    print_di(f_tag *tag)
{
    int di;

    di = va_arg(tag->ap, int);
    tag->size = digits_count(di);
	if (di < 0)
		tag->width -= 1;
    if (tag->minus == 0)
        right_sort(tag, di);
    else
        left_sort(tag, di);
}

void    sort_spec(f_tag *tag)
{
    if (*tag->fmt == 'd' || *tag->fmt == 'i')
        print_di(tag);
}

void    sort_format(f_tag *tag)
{
    if (*tag->fmt == '-')
        tag->minus = 1;
    else if (*tag->fmt == '0' && ft_isdigit(*(tag->fmt - 1)) == 0)
        tag->zero = 1;
    else if (*tag->fmt == '*' || *tag->fmt == '.' || ft_isdigit(*tag->fmt) != 0)
        sort_width_prec(tag);
    else if (strchr_spec(*tag->fmt) != 0)
        sort_spec(tag);
}

void    check_format(f_tag *tag)
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
                sort_format(tag);
            sort_format(tag);
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
    check_format(&tag);
    va_end(tag.ap);
    return (tag.res);
}

int     main(void)
{
    ft_printf("imt : %08.3d\n", 8375);
    printf("org : %8.3d\n", -216);
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
