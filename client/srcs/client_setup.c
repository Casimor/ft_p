/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 12:01:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/15 15:18:53 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		check_port(char *port)
{
	int			i;

	i = 0;
	while (port[i] != '\0')
	{
		if (port[i] < '0' || port[i] > '9')
		{
			printf("Invalid port.\n");
			return (0);
		}
		++i;
	}
	return (1);
}

static int		close_socket(int socket)
{
	close(socket);
	return (-1);
}

static int		create_client(char **args)
{
	int			client_sock;
	t_proto		*proto;
	t_sock		client_in;

	if ((proto = getprotobyname("tcp")) == 0)
	{
		printf("Couldn't get tcp protocol.\n");
		return (-1);
	}
	if ((client_sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) < 0)
	{
		printf("Invalid client socket.\n");
		return (-1);
	}
	if (!check_port(args[2]))
		return (close_socket(client_sock));
	client_in.sin_port = htons(ft_atoi(args[2]));
	client_in.sin_addr.s_addr = inet_addr(args[1]);
	client_in.sin_family = AF_INET;
	if (connect(client_sock, (t_saddr *)&client_in, sizeof(client_in)) < 0)
	{
		printf("Connect error.\n");
		return (close_socket(client_sock));
	}
	return (client_sock);
}

void			init_client(t_client *client, char **av)
{
	client->socket = create_client(av);
	if (client->socket > 0)
	{
		client->user = get_user(client->socket);
		client->s_pwd = 0;
		client->c_pwd = 0;
		client->c_old_pwd = 0;
		ft_bzero(&client->buff, BUF_SIZE);
	}
}
