/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 16:30:03 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 17:32:59 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		ls_command(char *str, t_client *client)
{
	int		r;

	r = 0;
	if (send_wrapper(client->socket, str, ft_strlen(str)))
	{
		while ((r = (recv(client->socket, client->buff, BUF_SIZE, 0))) > 0)
		{
			if (!ft_strncmp(client->buff, "ls", 2))
			{
				ft_putendl("\033[31mERROR\033[0m");
				r = 2;
			}
			ft_putstr(client->buff);
			if (ft_strlen(client->buff) < BUF_SIZE)
			{
				ft_bzero(client->buff, BUF_SIZE);
				break ;
			}
			ft_bzero(client->buff, BUF_SIZE);
		}
		if (r == -1)
			printf("\033[31mERROR\033[0m\nRecv error.\n");
		else if (r != 2)
			SUCCESS;
	}
}

void		lls_command(char *str, t_client *client)
{
	pid_t	process;
	char	**args;

	(void)client;
	args = ft_strsplit(str, ' ');
	process = fork();
	if (process < 0)
		printf("Fork error\n");
	else if (process == 0)
	{
		execv("/bin/ls", args);
		ft_array_free(args);
		exit(0);
	}
	else
		wait4(process, 0, 0, 0);
	SUCCESS;
	ft_array_free(args);
}
