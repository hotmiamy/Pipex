/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:06:19 by coder             #+#    #+#             */
/*   Updated: 2022/03/09 18:06:44 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	if (!len)
		return (0);
	while (*s1 && *s2 && --len)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((*(unsigned char *)s1 - *(unsigned char *)s2));
}

char	*ft_strdup(const char *str)
{
	char	*alloc_str;
	int		inx;

	alloc_str = (char *)malloc(ft_strlen(str) + 1);
	inx = 0;
	if (!alloc_str)
		return (NULL);
	while (str[inx])
	{
		alloc_str[inx] = str[inx];
		inx++;
	}
	alloc_str[inx] = '\0';
	return (alloc_str);
}

char	*ft_substr(char const *str, unsigned int start, size_t sub_str_len)
{
	size_t		strlen;
	char		*substr;
	size_t		index;

	if (!str)
		return (0);
	strlen = ft_strlen(str);
	if (start > strlen)
		return (ft_strdup(""));
	else if (strlen <= sub_str_len)
		sub_str_len = strlen - start;
	substr = (char *)malloc(sub_str_len + 1);
	if (!substr)
		return (0);
	index = 0;
	while (str[index + start] && index < sub_str_len)
	{
		substr[index] = str[index + start];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str_conca;
	int		str_concalen;
	int		index;
	int		index2;

	if (!str1 || !str2)
		return (NULL);
	str_concalen = ft_strlen(str1) + ft_strlen(str2) + 1;
	str_conca = (char *)malloc(str_concalen * sizeof(char));
	if (!str_conca)
		return (0);
	index = 0;
	while (str1[index])
	{
		str_conca[index] = str1[index];
		index++;
	}
	index2 = 0;
	while (str2[index2])
	{
		str_conca[index + index2] = str2[index2];
		index2++;
	}
	str_conca[index + index2] = '\0';
	return (str_conca);
}
