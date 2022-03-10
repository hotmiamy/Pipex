/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:32:01 by coder             #+#    #+#             */
/*   Updated: 2022/03/10 19:59:09 by coder            ###   ########.fr       */
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

char	*get_env(char **envp)
{
	char	*path_env;

	while (*envp)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
		{
			path_env = ft_strdup(*envp + 5);
			return (path_env);
		}
		envp++;
	}
	return (0);
}

int	main(int argc, char *argv [], char *envp [])
{
	char	*path_variable;
	char	**all_variable_path;
	char	*path_cmd;
	char	**arr;

	path_variable = get_env(envp);
	all_variable_path = ft_split(path_variable, ':');
	if (argc > 1)
	{
		arr = ft_split(argv[1], ' ');
		path_cmd = get_command(all_variable_path, arr[0]);
		execve(path_cmd, arr, all_variable_path);
	}
	return (0);
}
