/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 05:13:46 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/28 09:08:48 by jaehpark         ###   ########.fr       */
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
	int				max;
	int				min;
	int				pivot;
	int				p_max;
}					t_info;

int					*ft_intset(int *b, int c, size_t len);
long long			ft_atol(char *s);
void				exit_msg(void);
void				ft_msg(char *s);
void				push_a_max(int *a, int *b, t_info *info);
int					check_sort_a(int *a, t_info *info);
int					check_sort_b(int *b, t_info *info);
int					check_max(int *n, int num);
int					check_min(int *n, int num);
int					check_pivot(int *n, int num, t_info *info, char c);
int					check_p_max(int *b, t_info *info);
void				sort_stack(int *a, int *b, t_info *info);
void				sort_stack2(int *a, int *b, t_info *info);
void				sort_stack3(int *a, int *b, t_info *info);
void				sort_stack4(int *a, int *b, t_info *info);
void				init_info(t_info *info, int argc);
void				init_stack(int **a, int **b, t_info info, char **argv);
void				init_pivot(int *n, int num, t_info *info);
char				*swap_a(int *a);
char				*swap_b(int *b);
char				*swap_ab(int *a, int *b, t_info *info);
char				*push_a(int *a, int *b, t_info *info);
char				*push_b(int *b, int *a, t_info *info);
char				*rotate_a(int *a, t_info *info);
char				*rotate_b(int *b, t_info *info);
char				*rotate_ab(int *a, int *b, t_info *info);
char				*reverse_rotate_a(int *a, t_info *info);
char				*reverse_rotate_b(int *b, t_info *info);
char				*reverse_rotate_ab(int *a, int *b, t_info *info);

#endif
