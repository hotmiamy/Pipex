/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:31:40 by llopes-n          #+#    #+#             */
/*   Updated: 2022/03/17 22:55:05 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
