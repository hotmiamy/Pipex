/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:45:13 by coder             #+#    #+#             */
/*   Updated: 2022/04/13 22:01:35 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	error_exit(char *cmd, char *msg, int exit_code, t_pipex *pipex)
{
	write(2, cmd, strlen(cmd));
	write(2, msg, strlen(msg));
	close_fds(pipex);
	free_matrix(pipex->all_cmd_path);
	free_matrix(pipex->cmd_arg);
	exit(exit_code);
}
