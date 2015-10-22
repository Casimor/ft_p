/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 10:44:41 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:38:26 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static const t_command		g_commands[] = {
	{ "ls", &ls_command },
	{ "pwd", &pwd_command },
	{ "cd", &cd_command },
	{ "get", &get_command },
	{ "put", &put_command }
};

void			read_message(t_client *client)
{
	int		r;

	if ((r = recv(client->socket, client->read_buf, BUF_SIZE, 0)) < 0)
		printf("Receive error\n");
	else
		client->received = r;
}

void			send_message(t_client *client)
{
	if (send(client->socket, client->write_buf, client->to_send, 0) < 0)
		printf("Send error\n");
	ft_bzero(&client->write_buf, BUF_SIZE);
	client->to_send = 0;
}

static void		check_command(t_client *client, t_info *data)
{
	size_t		i;
	char		**args;

	i = 0;
	args = ft_strsplit(client->read_buf, ' ');
	if (args[0])
	{
		while (i < sizeof(g_commands) / sizeof(t_command))
		{
			if (!ft_strcmp(g_commands[i].command, args[0]))
			{
				printf("User %s requested \"%s\".\n",
						client->name, client->read_buf);
				g_commands[i].f(client, args, data);
				ft_bzero(client->read_buf, BUF_SIZE);
				client->received = 0;
				break ;
			}
			++i;
		}
	}
	ft_array_free(args);
}

void			handle_message(t_client *client, t_info *data)
{
	if (client->get || client->put)
		return ;
	if (!client->home)
	{
		client->home = ft_strdup(data->home);
		client->pwd = 0;
	}
	check_command(client, data);
}
