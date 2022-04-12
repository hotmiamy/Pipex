/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:10:34 by coder             #+#    #+#             */
/*   Updated: 2022/04/12 21:42:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static void	put_space(char *str_cmd)
{
	int		inx;

	inx = 0;
	while (str_cmd[inx])
	{
		if (str_cmd[inx] == '\'')
		{
			inx++;
			while (str_cmd[inx] != '\'' && str_cmd[inx] != '\0')
			{
				if (str_cmd[inx] == 1)
					str_cmd[inx] = ' ';
				inx++;
			}
		}
		inx++;
	}
}

static void	rm_space(char *str_cmd)
{
	int		inx;

	inx = 0;
	while (str_cmd[inx])
	{
		if (str_cmd[inx] == '\'')
		{
			inx++;
			while (str_cmd[inx] != '\'' && str_cmd[inx] != '\0')
			{
				if (str_cmd[inx] == ' ')
					str_cmd[inx] = 1;
				inx++;
			}
		}
		inx++;
	}
}

char	*rm_quotes(char *str)
{
	int		inx;
	int		str_len;
	char	*new_str;

	inx = 0;
	str_len = 0;
	while (str[inx])
	{
		if (str[inx] != '\'')
			str_len++;
		inx++;
	}
	new_str = ft_calloc(str_len + 1, sizeof(char));
	inx = 0;
	while (*str)
	{
		if (*str != '\'')
		{
			new_str[inx] = *str;
			inx++;
		}
		str++;
	}
	return (new_str);
}

void	treat_cmd(t_pipex *pipex, char *str_cmd)
{
	int		inx;
	int		iny;

	iny = 0;
	rm_space(str_cmd);
	pipex->cmd_arg = ft_split(str_cmd, ' ');
	while (pipex->cmd_arg[iny])
	{
		put_space(pipex->cmd_arg[iny]);
		inx = 0;
		while (pipex->cmd_arg[iny][inx])
		{
			if (pipex->cmd_arg[iny][inx] == '\'')
				pipex->cmd_arg[iny] = rm_quotes(pipex->cmd_arg[iny]);
			inx++;
		}
		iny++;
	}
}
