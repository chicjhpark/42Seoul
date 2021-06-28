/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:28:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/28 09:03:42 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_swap_push(int *a, int *b, t_info *info, char *buf)
{
	if (buf[0] == 's' && buf[1] == 'a' && buf[2] == '\n')
		swap_a(a);
	else if (buf[0] == 's' && buf[1] == 'b' && buf[2] == '\n')
		swap_b(b);
	else if (buf[0] == 's' && buf[1] == 's' && buf[2] == '\n')
	{
		swap_a(a);
		swap_b(b);
	}
	else if (buf[0] == 'p' && buf[1] == 'a' && buf[2] == '\n')
		push_a(a, b, info);
	else if (buf[0] == 'p' && buf[1] == 'b' && buf[2] == '\n')
		push_b(b, a, info);
	else
		return (FALSE);
	return (TRUE);
}

int		ft_rotate(int *a, int *b, t_info *info, char *buf)
{
	if (buf[0] == 'r' && buf[1] == 'a' && buf[2] == '\n')
		rotate_a(a, info);
	else if (buf[0] == 'r' && buf[1] == 'b' && buf[2] == '\n')
		rotate_b(b, info);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == '\n')
	{
		rotate_a(a, info);
		rotate_b(b, info);
	}
	else
		return (FALSE);
	return (TRUE);
}

int		ft_reverse_rotate(int *a, int *b, t_info *info, char *buf)
{
	char	line;

	read(0, &line, 1);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'a' && line == '\n')
		reverse_rotate_a(a, info);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'b' && line == '\n')
		reverse_rotate_b(b, info);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'r' && line == '\n')
	{
		reverse_rotate_a(a, info);
		reverse_rotate_b(b, info);
	}
	else
		return (FALSE);
	return (TRUE);
}

void	sort_operation(int *a, int *b, t_info *info)
{
	char	buf[3];

	while (read(0, &buf, sizeof(buf)) != 0)
	{
		if (buf[0] != 's' && buf[0] != 'p' && buf[0] != 'r')
			exit_msg();
		if (ft_swap_push(a, b, info, buf) == FALSE)
			if (ft_rotate(a, b, info, buf) == FALSE)
				if (ft_reverse_rotate(a, b, info, buf) == FALSE)
					exit_msg();
	}
	if (check_sort_a(a, info) == TRUE && info->a_num == info->num)
		ft_msg("OK");
	else
		ft_msg("KO");
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	t_info	info;

	if (argc >= 2)
	{
		init_info(&info, argc);
		init_stack(&a, &b, info, &argv[1]);
		if (check_sort_a(a, &info) == TRUE)
			ft_msg("OK");
		else
			sort_operation(a, b, &info);
		free(a);
		free(b);
	}
	return (0);
}
