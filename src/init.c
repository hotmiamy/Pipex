/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:04:25 by coder             #+#    #+#             */
/*   Updated: 2022/03/22 21:48:03 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	open_files(t_pipex *pipex, char **argv, int argc)
{
	char	*error_msg;

	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		error_msg = ft_strdup(argv[1]);
		write(2, error_msg, ft_strlen(error_msg));
		write(2, ": No such file or directory or access denied\n", 46);
		free(error_msg);
	}
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_RDWR | O_CREAT, 0644);
	if (pipex->outfile < 0)
	{
		error_msg = ft_strdup(argv[argc - 1]);
		perror(error_msg);
		free(error_msg);
		exit(1);
	}
	pipe(pipex->pipe);
}

void	get_env(t_pipex *pipex, char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
		{
			pipex->all_cmd_path = ft_split(*envp + 5, ':');
			break ;
		}
		envp++;
	}
}
