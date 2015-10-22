/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 11:10:28 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 16:11:21 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		ls_command(t_client *client, char **args, t_info *data)
{
	pid_t	process;

	(void)data;
	go_pwd(client);
	process = fork();
	if (process < 0)
		printf("Fork error\n");
	else if (process == 0)
	{
		dup2(client->socket, STDOUT);
		dup2(client->socket, STDERR);
		execv("/bin/ls", args);
		close(client->socket);
		exit(0);
	}
	else
		wait4(process, 0, 0, 0);
}
