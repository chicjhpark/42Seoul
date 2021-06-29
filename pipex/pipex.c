/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:13:08 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/29 12:15:03 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

typedef struct	s_cmd
{
	char		*file1;
	char		*file2;
	char		*cmd;
}				t_cmd;

void	malloc_cmd(int argc, char **argv, t_cmd *cmd)
{
	int		num1;
	int		num2;
	int		num3;
	int		i;

	num1 = ft_strlen(argv[1]);
	num2 = ft_strlen(argv[argc - 1]);
	num3 = 0;
	i = 2;
	while (i < argc - 1)
	{
		num3 += ft_strlen(argv[i]) + 1;
		i++;
	}
	cmd->file1 = (char *)malloc(sizeof(char) * (num1 + 1));
	cmd->file2 = (char *)malloc(sizeof(char) * (num2 + 1));
	cmd->cmd = (char *)malloc(sizeof(char) * (num3 + 1));
}

char	*ft_strcpy(char *s1, char *s2)
{
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
}

void	init_cmd(int argc, char **argv, t_cmd *cmd)
{
	cmd->file1 = ft_strcpy
}

int		main(int argc, char **argv)
{
	t_cmd	cmd;

	if (argc > 4)
	{
		malloc_cmd(argc, argv, &cmd);
		init_cmd(argc, argv, &cmd);
	}
	return (0);
}
