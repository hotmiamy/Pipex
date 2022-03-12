/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:08:24 by coder             #+#    #+#             */
/*   Updated: 2022/03/12 01:48:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*get_command(char **cmd_paths, char *arg_cmd)
{
	char	*tmp;
	char	*cmd;

	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		cmd = ft_strjoin(tmp, arg_cmd);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		cmd_paths++;
	}
	return (0);
}

void	pid1(t_pipex pipex, char *argv [], char **envp)
{
	dup2(pipex.pipe[STDOUT_FILENO], STDOUT_FILENO);
	close(pipex.pipe[STDIN_FILENO]);
	dup2(pipex.infile, STDIN_FILENO);
	pipex.cmd_arg = ft_split(argv[2], ' ');
	pipex.cmd = get_command(pipex.all_cmd_path, pipex.cmd_arg[0]);
	if (pipex.cmd == 0)
	{
		free_child(&pipex);
		error_msg("command not found");
		exit(127);
	}
	execve(pipex.cmd, pipex.cmd_arg, envp);
}

void	pid2(t_pipex pipex, char *argv [], char **envp)
{
	dup2(pipex.pipe[STDIN_FILENO], STDIN_FILENO);
	close(pipex.pipe[STDOUT_FILENO]);
	dup2(pipex.outfile, STDOUT_FILENO);
	pipex.cmd_arg = ft_split(argv[3], ' ');
	pipex.cmd = get_command(pipex.all_cmd_path, pipex.cmd_arg[0]);
	if (pipex.cmd == 0)
	{
		free_child(&pipex);
		error_msg("invalid command");
		exit(127);
	}
	execve(pipex.cmd, pipex.cmd_arg, envp);
}
