/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:32:01 by coder             #+#    #+#             */
/*   Updated: 2022/03/12 01:43:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

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
	char	*path_env;
	t_pipex	pipex;
	int		exit_code;

	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		error_exit("infile: No such file or directory", 0);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_RDWR | O_CREAT, 0644);
	if (pipex.outfile < 0)
		error_exit("outfile: Permission denied", 1);
	pipe(pipex.pipe);
	path_env = get_env(envp);
	pipex.all_cmd_path = ft_split(path_env, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		pid1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		pid2(pipex, argv, envp);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	waitpid(pipex.pid1, &exit_code, 0);
	waitpid(pipex.pid2, &exit_code, 0);
	return (0);
}
