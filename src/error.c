/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:45:13 by coder             #+#    #+#             */
/*   Updated: 2022/04/11 22:31:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	error_exit(char *msg, int exit_code, t_pipex *pipex)
{
	perror(msg);
	close_fds(pipex);
	free_matrix(pipex->all_cmd_path);
	free_matrix(pipex->cmd_arg);
	exit(exit_code);
}
