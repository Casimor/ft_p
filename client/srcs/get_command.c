/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 14:19:04 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:34:44 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	get_file(t_client *client, int fd)
{
	int		r;

	while ((r = read(client->socket, client->buff, BUF_SIZE)) > 0)
	{
		if (write(fd, client->buff, r) < 0)
		{
			ERROR;
			printf("Write error.\n");
			return (0);
		}
		ft_bzero(client->buff, BUF_SIZE);
		if (r < BUF_SIZE)
			return (1);
		if (!send_wrapper(client->socket, "OK", 2))
			return (0);
	}
	if (r == -1)
	{
		ERROR;
		printf("Read error.\n");
		return (0);
	}
	return (1);
}

static int	open_file(t_client *client, char *file)
{
	int		fd;

	if (!recv_wrapper(client))
	{
		ft_bzero(client->buff, BUF_SIZE);
		return (0);
	}
	fd = open(file, O_WRONLY | O_CREAT, ft_atoi(client->buff));
	if (fd < 0)
	{
		ERROR;
		printf("Open error\n");
		return (0);
	}
	ft_bzero(client->buff, BUF_SIZE);
	if (!send_wrapper(client->socket, "OK", 2))
	{
		close(fd);
		return (0);
	}
	return (fd);
}

static int	get_init(t_client *client, char *file)
{
	if (!recv_wrapper(client))
	{
		ft_bzero(client->buff, BUF_SIZE);
		return (0);
	}
	if (!ft_strcmp(client->buff, "error"))
	{
		ERROR;
		ft_bzero(client->buff, BUF_SIZE);
		return (0);
	}
	else if (!ft_strcmp(client->buff, "OK"))
	{
		if (file_exist(file))
		{
			send_wrapper(client->socket, "NOPE", 4);
			return (-1);
		}
		ft_bzero(client->buff, BUF_SIZE);
		if (!send_wrapper(client->socket, "OK", 2))
			return (0);
	}
	return (1);
}

void		get_command(char *str, t_client *client)
{
	char	**args;
	int		fd;
	int		r;

	if (error_cmd(str, "get"))
		return ;
	if (send_wrapper(client->socket, str, ft_strlen(str)))
	{
		args = ft_strsplit(str, ' ');
		if ((r = get_init(client, args[1])) == 1)
		{
			r = 0;
			fd = open_file(client, args[1]);
			if (fd > 0)
			{
				r = get_file(client, fd);
				close(fd);
			}
		}
		if (r == 0)
			printf("Error getting file \"%s\"\n", args[1]);
		if (r == 1)
			SUCCESS;
		ft_array_free(args);
	}
}
