/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 10:41:53 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:39:56 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int	check_port(char *port)
{
	int		i;

	i = 0;
	while (port[i] != '\0')
	{
		if (port[i] < '0' || port[i] > '9')
		{
			printf("Invalid port\n");
			return (0);
		}
		++i;
	}
	return (1);
}

static int	close_socket(int socket)
{
	close(socket);
	return (-1);
}

int			init_server(char *port)
{
	int		serv_sock;
	t_sock	serv_in;

	if ((serv_sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Invalid server socket\n");
		return (-1);
	}
	if (!check_port(port))
		return (close_socket(serv_sock));
	ft_bzero(&serv_in, sizeof(serv_in));
	serv_in.sin_port = htons(ft_atoi(port));
	serv_in.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_in.sin_family = PF_INET;
	if (bind(serv_sock, (t_saddr *)&serv_in, sizeof(serv_in)) < 0)
	{
		printf("Couldn't bind specified port\n");
		return (close_socket(serv_sock));
	}
	if (listen(serv_sock, MAX_CLIENTS) < 0)
	{
		printf("Listen error\n");
		return (close_socket(serv_sock));
	}
	return (serv_sock);
}
