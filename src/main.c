/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:32:01 by coder             #+#    #+#             */
/*   Updated: 2022/03/30 23:17:21 by coder            ###   ########.fr       */
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
	int		exit_codepid1;
	int		exit_codepid2;

	pipex.exit_code = 0;
	if (argc != 5)
		error_exit("Invalid number of arguments \n", 1);
	open_files(&pipex, argv, argc);
	get_env(&pipex, envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		pid1(&pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		pid2(&pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(pipex.pid1, &exit_codepid1, WUNTRACED);
	waitpid(pipex.pid2, &exit_codepid2, 0);
	free_matrix(pipex.all_cmd_path);
	close_fds(&pipex);
	if (exit_codepid2 > 0)
		pipex.exit_code = exit_codepid2;
	return (pipex.exit_code);
}
