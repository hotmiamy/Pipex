/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:08:24 by coder             #+#    #+#             */
/*   Updated: 2022/03/28 22:39:29 by coder            ###   ########.fr       */
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
		free(tmp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		cmd_paths++;
	}
	return (NULL);
}

void	pid1(t_pipex *pipex, char *argv [], char **envp)
{
	char	*error_msg;

	dup2(pipex->pipe[STDOUT_FILENO], STDOUT_FILENO);
	close(pipex->pipe[STDIN_FILENO]);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
	{
		free_matrix(pipex->all_cmd_path);
		close(pipex->outfile);
		exit(-1);
	}
	pipex->cmd_arg = ft_split(argv[2], ' ');
	pipex->cmd = get_command(pipex->all_cmd_path, pipex->cmd_arg[0]);
	if (!pipex->cmd)
	{
		error_msg = ft_strdup(pipex->cmd_arg[0]);
		perror(error_msg);
		close_fds(pipex);
		free_matrix(pipex->all_cmd_path);
		free_matrix(pipex->cmd_arg);
		free(error_msg);
		exit(127);
	}
	execve(pipex->cmd, pipex->cmd_arg, envp);
}

void	pid2(t_pipex *pipex, char *argv [], char **envp)
{
	char	*error_msg;

	dup2(pipex->pipe[STDIN_FILENO], STDIN_FILENO);
	close(pipex->pipe[STDOUT_FILENO]);
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
	{
		free_matrix(pipex->all_cmd_path);
		close(pipex->infile);
		exit(-1);
	}
	pipex->cmd_arg = ft_split(argv[3], ' ');
	pipex->cmd = get_command(pipex->all_cmd_path, pipex->cmd_arg[0]);
	if (!pipex->cmd)
	{
		error_msg = ft_strdup(pipex->cmd_arg[0]);
		perror(error_msg);
		close_fds(pipex);
		free_matrix(pipex->all_cmd_path);
		free_matrix(pipex->cmd_arg);
		free(error_msg);
		exit(127);
	}
	execve(pipex->cmd, pipex->cmd_arg, envp);
}
