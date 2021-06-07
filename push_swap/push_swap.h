/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 05:13:46 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/08 07:18:56 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define TRUE	0
# define FALSE	1

typedef struct		s_info
{
	int				num;
	int				a_num;
	int				b_num;
	int				pivot_a;
	int				pivot_b;
}					t_info;

long long			ft_atol(char *s);
void				exit_msg(void);
void				ft_msg(char *s);
int					check_sort_a(int *n, int n_num);
int					check_sort_b(int *n, int n_num);
int					check_largest(int *n, int i, int num);
int					check_smallest(int *n, int i, int num);
void				print_result(int *a, int *b, t_info info);
void				init_info(t_info *info, int argc);
void				init_stack(int *a, int *b, t_info info, char **argv);
void				init_pivot(int *a, int *b, t_info *info);
void				ft_swap(int *n, char c);
void				ft_push(int *n, int *n2, int *n_num, int *n2_num);
void				ft_rotate(int *n, int num, char c);
void				ft_reverse_rotate(int *n, int num, char c);

#endif