/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:02:16 by coder             #+#    #+#             */
/*   Updated: 2022/03/12 01:07:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**all_cmd_path;
	char	**cmd_arg;
	char	*cmd;
	int		infile;
	int		outfile;
	int		pipe[2];
	int		pid1;
	int		pid2;
}	t_pipex;

size_t	ft_strlen(const char *str);
int		main(int argc, char *argv [], char *envp []);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		error_msg(char *msg);
char	*ft_strdup(const char *str);
char	**ft_split(char const *str, char chr);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *str1, const char *str2);
void	pid1(t_pipex pipex, char *argv [], char **envp);
void	pid2(t_pipex pipex, char *argv [], char **envp);
void	free_child(t_pipex *pipex);
void	free_parent(t_pipex *pipex);
void	error_exit(char *msg, int exit_code);
#endif