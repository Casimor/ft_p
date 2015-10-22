/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 11:58:24 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:38:01 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void		get_init(t_client *client)
{
	t_stat		file_stat;
	char		*mode;

	fstat(client->fd, &file_stat);
	mode = ft_itoa(file_stat.st_mode);
	ft_strcpy(client->write_buf, mode);
	client->to_send = ft_strlen(mode);
	free(mode);
	client->get = READY;
	client->synchro = 0;
}

static void		get_file(t_client *client)
{
	int			n;

	n = read(client->fd, &client->write_buf, BUF_SIZE);
	if (n < 0)
		printf("Read error\n");
	else if (n < BUF_SIZE)
	{
		close(client->fd);
		client->get = NONE;
		client->fd = -1;
	}
	client->to_send = n;
	client->synchro = 0;
}

void			get_handle(t_client *client)
{
	if (!ft_strcmp(client->read_buf, "NOPE"))
	{
		client->get = NONE;
		ft_bzero(&client->read_buf, BUF_SIZE);
		return ;
	}
	if (!ft_strcmp(client->read_buf, "OK"))
	{
		client->synchro = 1;
		ft_bzero(&client->read_buf, BUF_SIZE);
	}
	if (client->get == ANSWER)
		client->get = INIT;
	else if (client->get == INIT && client->synchro)
		get_init(client);
	else if (client->get == READY && client->synchro)
		get_file(client);
}

void			get_command(t_client *client, char **args, t_info *data)
{
	(void)data;
	client->fd = open(args[1], O_RDONLY);
	if (client->fd < 0)
	{
		ft_strcpy(client->write_buf, "error");
		client->to_send = 5;
	}
	else
	{
		ft_strcpy(client->write_buf, "OK");
		client->to_send = 2;
		client->get = ANSWER;
	}
}
