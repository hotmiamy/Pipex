/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:32:01 by coder             #+#    #+#             */
/*   Updated: 2022/04/13 18:42:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	close_pipe(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

int	main(int argc, char *argv [], char *envp [])
{
	t_pipex	pipex;

	pipex.exit_code = 0;
	if (argc != 5)
	{
		perror("Invalid number of arguments \n");
		exit(1);
	}
	open_files(&pipex, argv, argc);
	get_env(&pipex, envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		pid1(&pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		pid2(&pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(pipex.pid1, &pipex.exit_code, 0);
	waitpid(pipex.pid2, &pipex.exit_code, 0);
	free_matrix(pipex.all_cmd_path);
	close_fds(&pipex);
	return (WEXITSTATUS(pipex.exit_code));
}
