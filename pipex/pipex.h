/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:13:22 by jaehpark          #+#    #+#             */
/*   Updated: 2021/07/13 03:46:46 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include "libft.h"

typedef struct	s_cmd
{
	char		*infile;
	char		*outfile;
	int			fd[2];
	char		*data;
	char		**path;
	char		***cmd;
}				t_cmd;

void	exit_msg(char *msg);
void	ft_strncpy(char *s1, char *s2, int n);
int		find_path_idx(char **envp, char *name);
char	*ft_strcat(char *s1, char *s2);
void	parse_cmd(t_cmd *cmd, int argc, char **argv);
void	parse_path(t_cmd *cmd, char **envp);
void	parse_file(t_cmd *cmd, int argc, char **argv);
void	exe_cmd(t_cmd *cmd);

#endif
