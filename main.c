/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:32:01 by coder             #+#    #+#             */
/*   Updated: 2022/02/25 01:33:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv)
{
	char	**env;
	char	**arr;

	arr = malloc(2 * sizeof(char *));
	env = malloc(2 * sizeof(char *));
	env[0] = "TEST=teste";
	env[1] = NULL;
	arr[0] = "/bin/ls";
	arr[1] = NULL;
	execve("/bin/ls", arr, env);
	return (0);
}
