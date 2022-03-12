/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:32:24 by coder             #+#    #+#             */
/*   Updated: 2022/03/12 01:08:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	free_parent(t_pipex *pipex)
{
	int	index;

	close(pipex->infile);
	close(pipex->outfile);
	index = 0;
	while (pipex->all_cmd_path)
	{
		free(pipex->all_cmd_path[index]);
		index++;
	}
	free(pipex->all_cmd_path[index]);
}

void	free_child(t_pipex *pipex)
{
	int	index;

	index = 0;
	while (pipex->all_cmd_path)
	{
		free(pipex->all_cmd_path[index]);
		index++;
	}
	free(pipex->all_cmd_path[index]);
}
