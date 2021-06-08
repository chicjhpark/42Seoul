/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 05:13:46 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/09 00:07:27 by jaehpark         ###   ########.fr       */
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
	int				pivot;
	int				pivot_i;
}					t_info;

long long			ft_atol(char *s);
void				exit_msg(void);
void				ft_msg(char *s);
int					check_sort_a(int *a, t_info *info);
int					check_sort_b(int *b, t_info *info);
int					check_largest(int *n, int i, int num);
int					check_smallest(int *n, int i, int num);
void				print_result(int *a, int *b, t_info info);
void				init_info(t_info *info, int argc);
void				init_stack(int *a, int *b, t_info info, char **argv);
char				*swap_a(int *a);
char				*swap_b(int *b);
char				*push_a(int *a, int *b, t_info *info);
char				*push_b(int *b, int *a, t_info *info);
char				*rotate_a(int *a, t_info *info);
char				*rotate_b(int *b, t_info *info);
char				*reverse_rotate_a(int *a, t_info *info);
char				*reverse_rotate_b(int *b, t_info *info);

#endif