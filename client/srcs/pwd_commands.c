/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 16:30:49 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 17:14:16 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		pwd_command(char *str, t_client *client)
{
	int		r;

	r = 0;
	if (send(client->socket, str, ft_strlen(str), 0) < 0)
		printf("\033[31mERROR\033[0m\nSend error.\n");
	else
	{
		while ((r = (recv(client->socket, client->buff, BUF_SIZE, 0))) > 0)
		{
			if (!ft_strncmp(client->buff, "usage", 5))
			{
				printf("\033[31mERROR\033[0m\n%s", client->buff);
				return ;
			}
			ft_putstr(client->buff);
			if (ft_strlen(client->buff) < BUF_SIZE)
				break ;
			ft_bzero(client->buff, BUF_SIZE);
		}
		if (r == -1)
			printf("\033[31mERROR\033[0m\nRecv error.\n");
		if (r != -1)
			SUCCESS;
	}
}

void		lpwd_command(char *str, t_client *client)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_strsplit(str, ' ');
	while (args[i])
		i++;
	if (i != 1)
		printf("\033[31mERROR\033[0m\npwd: too many arguments\n");
	else
	{
		getcwd(client->buff, BUF_SIZE);
		printf("%s\n", client->buff);
		SUCCESS;
	}
	ft_array_free(args);
}
