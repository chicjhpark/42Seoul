/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:13:08 by jaehpark          #+#    #+#             */
/*   Updated: 2021/07/05 17:39:00 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

typedef struct	s_cmd
{
	char		**cmd;
	int			num;
}				t_cmd;

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	error_msg(const char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void	debug(t_cmd cmd)
{
	int		i;

	i = 0;
	while (i < cmd.num)
	{
		printf("%s", cmd.cmd[i]);
		if (cmd.cmd[i + 1])
			printf(" ");
		i++;
	}
	printf("\n");
}

void	init_cmd(int argc, char **argv, t_cmd *cmd)
{
	int		i;
	int		j;

	cmd->num = argc - 3 + (argc - 3) / 2;
	cmd->cmd = NULL;
	cmd->cmd = (char **)malloc(sizeof(char *) * cmd->num);
	if (cmd->cmd == NULL)
		exit(1);
	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		if (i != 2 && i % 2 == 0)
		{
			cmd->cmd[j] = NULL;
			j++;
		}
		cmd->cmd[j] = argv[i];
		i++;
		j++;
	}
	cmd->cmd[i] = NULL;
}

void	parse_cmd(char **argv, t_cmd cmd)
{
	int		fd;
	int		i;
	char	**test;
	char	*path = "ls";

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error_msg("zsh : no such file or directory: file");
	test = (char **)malloc(sizeof(char) * 2);
	test[0] = path;
	test[1] = NULL;
	execve(test[0], test, NULL);
	execve(cmd.cmd[0], cmd.cmd, NULL);
	i = 0;
	/*while (cmd.cmd[i])
	{
		execve(cmd.cmd[i], cmd.cmd, NULL);
		i += 2;
	}*/
}

int		main(int argc, char **argv)
{
	t_cmd	cmd;

	if (argc > 2)
	{
		init_cmd(argc, argv, &cmd);
		parse_cmd(argv, cmd);
		debug(cmd);
	}
	return (0);
}
