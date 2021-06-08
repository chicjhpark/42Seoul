/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 05:13:46 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/08 20:40:13 by jaehpark         ###   ########.fr       */
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
void				init_pivot(int *a, t_info *info);
char				*swap_a(int *a);
char				*swap_b(int *b);
char				*push_a(int *a, int *b, int *a_num, int *b_num);
char				*push_b(int *b, int *a, int *b_num, int *a_num);
char				*rotate_a(int *a, int num);
char				*rotate_b(int *b, int num);
char				*reverse_rotate_a(int *a, int num);
char				*reverse_rotate_b(int *b, int num);

#endif