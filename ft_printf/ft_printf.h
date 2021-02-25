/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:21:04 by jaehpark          #+#    #+#             */
/*   Updated: 2021/02/26 08:22:45 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_tag
{
	va_list	ap;
	char	*fmt;
	char	*str;
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		size;
	int		dot;
	int		res;
	int		nbr;
	int		lspace;
	int		rspace;
}				t_tag;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_isdigit(char c);
int		strchr_spec(char c);
char	*ft_itoa_sign(f_tag *tag);
void	digits_size(f_tag *tag);
void	sort_width_prec(f_tag *tag);
void	init_tag(f_tag *tag);
void	check_tag(f_tag *tag);
void	print_di(f_tag *tag);

#endif
