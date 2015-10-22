/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 11:59:10 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 15:13:57 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void		put_init(t_client *client)
{
	client->fd = open(client->file, O_WRONLY | O_CREAT | O_APPEND,
						ft_atoi(client->read_buf));
	if (client->fd < 0)
	{
		ft_strcpy(client->write_buf, "error");
		client->to_send = 5;
		client->put = NONE;
		client->fd = -1;
	}
	else
	{
		ft_strcpy(client->write_buf, "OK");
		client->to_send = 2;
		client->put = READY;
	}
	free(client->file);
	client->file = 0;
	ft_bzero(&client->read_buf, BUF_SIZE);
	client->received = 0;
}

static void		put_file(t_client *client)
{
	write(client->fd, client->read_buf, client->received);
	if (client->received < BUF_SIZE)
	{
		client->put = NONE;
		close(client->fd);
		client->fd = -1;
		free(client->file);
		client->file = 0;
	}
	else
	{
		ft_strcpy(client->write_buf, "OK");
		client->to_send = 2;
	}
	ft_bzero(&client->read_buf, BUF_SIZE);
	client->received = 0;
}

void			put_handle(t_client *client)
{
	if (client->put == ANSWER)
		client->put = INIT;
	else if (client->put == INIT && client->received > 0)
		put_init(client);
	else if (client->put == READY && client->received > 0)
		put_file(client);
}

void			put_command(t_client *client, char **args, t_info *data)
{
	(void)data;
	client->file = ft_strdup(args[1]);
	ft_strcpy(client->write_buf, "OK");
	client->to_send = 2;
	client->put = ANSWER;
}
