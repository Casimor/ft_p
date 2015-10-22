/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 10:39:59 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:38:08 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void		init_client(t_client *client, int socket, t_info *data)
{
	int			r;

	client->socket = socket;
	ft_bzero(client->name, BUF_SIZE);
	if ((r = recv(socket, client->name, BUF_SIZE - 1, 0)) < 0)
	{
		printf("Name receive error\n");
		ft_strcpy(client->name, "Anonymous");
		r = 9;
	}
	client->name[r] = 0;
	ft_strcpy(client->write_buf, data->home);
	client->to_send = ft_strlen(client->write_buf);
	client->received = 0;
	client->synchro = 0;
	client->get = NONE;
	client->put = NONE;
	client->fd = -1;
	client->file = 0;
	client->pwd = 0;
	client->old_pwd = 0;
	printf("New user %s connected !\n", client->name);
}

void			client_connection(t_server *server, t_client *clients,
										t_info *data)
{
	t_sock			client_in;
	unsigned int	client_size;
	int				client_sock;

	if (server->clients_nb == MAX_CLIENTS)
	{
		printf("Maximum number of connections reached.\n");
		return ;
	}
	client_size = sizeof(client_in);
	ft_bzero(&client_in, client_size);
	client_sock = accept(server->socket, (t_saddr *)&client_in, &client_size);
	if (client_sock == -1)
	{
		printf("Accept error\n");
		return ;
	}
	init_client(&clients[server->clients_nb], client_sock, data);
	server->clients_nb++;
}

void			client_disconnection(t_server *server, t_client *clients,
										int current)
{
	printf("User %s disconnected\n", clients[current].name);
	free(clients[current].file);
	close(clients[current].socket);
	ft_memmove(clients + current, clients + current + 1,
				(server->clients_nb - current - 1) * sizeof(*clients));
	server->clients_nb--;
}
