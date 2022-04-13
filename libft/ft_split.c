/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:07:53 by llopes-n          #+#    #+#             */
/*   Updated: 2022/04/11 21:37:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlettles(char *str, char delimiter)
{
	int	num_lettles;

	num_lettles = 0;
	while (str[num_lettles] != delimiter && str[num_lettles])
		num_lettles++;
	return (num_lettles);
}

static int	ft_num_worlds(char *str, char delimiter)
{
	int	index;
	int	number_worlds;

	index = 0;
	number_worlds = 0;
	while (str[index])
	{
		if (str[index] != delimiter)
		{
			number_worlds++;
			while (str[index] != delimiter && str[index])
				index++;
		}
		else
			index++;
	}
	return (number_worlds);
}

char	**ft_split(char const *str, char delim)
{
	char	**matrix;
	int		num_worlds;
	int		num_lettlers;
	int		array;

	if (!str)
		return (0);
	array = 0;
	num_worlds = ft_num_worlds((char *)str, delim);
	matrix = (char **)malloc((num_worlds + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	while (array < num_worlds)
	{
		while (*str == delim && *str)
			str++;
		num_lettlers = ft_numlettles((char *)str, delim);
		matrix[array] = ft_substr(str, 0, num_lettlers);
		str += num_lettlers + 1;
		array++;
	}
	matrix[array] = 0;
	return (matrix);
}
