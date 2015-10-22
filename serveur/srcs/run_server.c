/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 10:48:10 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:39:49 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int		get_max_socket(t_server *server, t_client *clients)
{
	int			i;
	int			max;

	i = 0;
	max = server->socket;
	while (i < server->clients_nb)
	{
		max = clients[i].socket > max ? clients[i].socket : max;
		++i;
	}
	return (max);
}

static void		check_fds(t_server *server, t_client *clients, t_info *data)
{
	int			i;

	i = 0;
	if (FD_ISSET(server->socket, &(server->read_fds)))
		client_connection(server, clients, data);
	else
	{
		while (i < server->clients_nb)
		{
			if (FD_ISSET(clients[i].socket, &(server->write_fds)))
				send_message(&clients[i]);
			if (FD_ISSET(clients[i].socket, &(server->read_fds)))
			{
				read_message(&clients[i]);
				if (clients[i].received == 0)
					client_disconnection(server, clients, i);
				else if (clients[i].received > 0)
					handle_message(&clients[i], data);
			}
			++i;
		}
	}
	if (FD_ISSET(STDIN, &(server->read_fds)))
		check_stdin(server);
}

static void		set_fds(t_server *server, t_client *clients)
{
	int			i;

	i = 0;
	FD_ZERO(&(server->read_fds));
	FD_ZERO(&(server->write_fds));
	FD_SET(STDIN, &(server->read_fds));
	FD_SET(server->socket, &(server->read_fds));
	while (i < server->clients_nb)
	{
		if (clients[i].to_send > 0)
			FD_SET(clients[i].socket, &(server->write_fds));
		FD_SET(clients[i].socket, &(server->read_fds));
		++i;
	}
}

static void		run_server(t_server *server, t_info *data)
{
	t_client	clients[MAX_CLIENTS];
	int			max;

	while (1)
	{
		handle_commands(server, clients);
		set_fds(server, clients);
		max = get_max_socket(server, clients);
		if (select(max + 1, &(server->read_fds),
							&(server->write_fds), 0, 0) == -1)
		{
			printf("Select error\n");
			break ;
		}
		check_fds(server, clients, data);
	}
}

void			run(char **av)
{
	t_server	server;
	t_info		data;

	if (av[2])
		init_home(av[2]);
	get_home(&data);
	server.socket = init_server(av[1]);
	if (server.socket > 0)
	{
		server.clients_nb = 0;
		run_server(&server, &data);
		close(server.socket);
	}
}
