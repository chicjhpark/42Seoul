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

void	check_operation(int *a, int *b, t_info *info, char *buf)
{
	if (buf[0] == 's' && buf[1] == 'a' && buf[2] == '\n')
		swap_a(a);
	else if (buf[0] == 's' && buf[1] == 'b' && buf[2] == '\n')
		swap_b(b);
	else if (buf[0] == 's' && buf[1] == 's' && buf[2] == '\n')
		checker_swap_ab(a, b);
	else if (buf[0] == 'p' && buf[1] == 'a' && buf[2] == '\n')
		push_a(a, b, info);
	else if (buf[0] == 'p' && buf[1] == 'b' && buf[2] == '\n')
		push_b(b, a, info);
	else if (buf[0] == 'r' && buf[1] == 'a' && buf[2] == '\n')
		rotate_a(a, info);
	else if (buf[0] == 'r' && buf[1] == 'b' && buf[2] == '\n')
		rotate_b(b, info);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == '\n')
		checker_rotate_ab(a, b, info);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'a' && buf[3] == '\n')
		reverse_rotate_a(a, info);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'b' && buf[3] == '\n')
		reverse_rotate_b(b, info);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'r' && buf[3] == '\n')
		checker_reverse_rotate_ab(a, b, info);
	else
		exit_msg();
}

void	sort_operation(int *a, int *b, t_info *info)
{
	char	buf[256];
	char	temp;
	int		i;

	temp = 0;
	while (read(0, &temp, 1) != 0)
	{
		ft_memset(buf, 0, sizeof(buf));
		buf[0] = temp;
		i = 1;
		while (temp != '\n' && read(0, &temp, 1) != 0)
		{
			buf[i] = temp;
			i++;
		}
		if (temp == EOF)
			break ;
		check_operation(a, b, info, buf);
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
		sort_operation(a, b, &info);
		free(a);
		free(b);
	}
	return (0);
}
