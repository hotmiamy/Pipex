/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:02:16 by coder             #+#    #+#             */
/*   Updated: 2022/04/11 22:31:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	char	**all_cmd_path;
	char	**cmd_arg;
	char	*cmd;
	int		exit_code;
	int		infile;
	int		outfile;
	int		pipe[2];
	int		pid1;
	int		pid2;
}	t_pipex;

size_t	ft_strlen(const char *str);
int		main(int argc, char *argv [], char *envp []);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
void	pid1(t_pipex *pipex, char *argv [], char **envp);
void	pid2(t_pipex *pipex, char *argv [], char **envp);
void	free_matrix(char **matrix);
void	free_ptr(char **ptr);
void	error_exit(char *msg, int exit_code, t_pipex *pipex);
void	open_files(t_pipex *pipex, char **argv, int argc);
void	get_env(t_pipex *pipex, char **envp);
void	close_fds(t_pipex *pipex);
void	treat_cmd(t_pipex *pipex, char *str_cmd);

#endif