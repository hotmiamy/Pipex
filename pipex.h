/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:02:16 by coder             #+#    #+#             */
/*   Updated: 2022/03/09 18:07:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);
int		main(int argc [], char *argv [], char *envp []);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *str);
char	**ft_split(char const *str, char chr);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *str1, const char *str2);
#endif