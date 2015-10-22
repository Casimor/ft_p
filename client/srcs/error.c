/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 15:21:14 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/19 18:14:21 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	cd_error(char *error, char *str)
{
	char	**args;

	if (!ft_strcmp(error, "error1"))
	{
		ERROR;
		printf("You can't go under the home directory.\n");
	}
	else if (!ft_strcmp(error, "error2"))
	{
		args = ft_strsplit(str, ' ');
		ERROR;
		printf("cd: no such file or directory: %s\n", args[1]);
		ft_array_free(args);
	}
}

int		error_cmd(char *str, char *name_cmd)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = ft_strsplit(str, ' ');
	while (cmd[i])
		i++;
	ft_array_free(cmd);
	if (i < 2)
	{
		printf("usage: %s <file>\n", name_cmd);
		return (1);
	}
	return (0);
}
