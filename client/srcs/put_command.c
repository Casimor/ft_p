/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 14:19:54 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 15:34:23 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	put_file(t_client *client, int fd)
{
	int		r;

	while ((r = read(fd, client->buff, BUF_SIZE)) > 0)
	{
		if (!send_wrapper(client->socket, client->buff, r))
			return (0);
		ft_bzero(client->buff, BUF_SIZE);
		if (r < BUF_SIZE)
			return (1);
		if (!recv_wrapper(client))
			return (0);
		if (ft_strcmp(client->buff, "OK"))
		{
			ft_bzero(client->buff, BUF_SIZE);
			return (0);
		}
		ft_bzero(client->buff, BUF_SIZE);
	}
	close(fd);
	if (r == -1)
	{
		printf("\033[31mERROR\033[0m\nRead error.\n");
		return (0);
	}
	return (1);
}

static int	put_init(t_client *client, int fd)
{
	if (!recv_wrapper(client))
		return (0);
	if (!ft_strcmp(client->buff, "error"))
	{
		ft_bzero(client->buff, BUF_SIZE);
		return (0);
	}
	return (put_file(client, fd));
}

static int	put_rights(t_client *client, int fd)
{
	t_stat	file_stat;
	char	*mode;

	if (!recv_wrapper(client))
		return (0);
	fstat(fd, &file_stat);
	mode = ft_itoa(file_stat.st_mode);
	if (!send_wrapper(client->socket, mode, ft_strlen(mode)))
	{
		ERROR;
		free(mode);
		printf("Send error.\n");
		return (0);
	}
	free(mode);
	return (1);
}

void		put_command(char *str, t_client *client)
{
	int		r;
	char	**args;
	int		fd;

	r = 0;
	if (error_cmd(str, "put"))
		return ;
	args = ft_strsplit(str, ' ');
	if ((fd = open(args[1], O_RDONLY)) < 0)
		printf("\033[31mERROR\033[0m\nCouldn't open file \"%s\"\n", args[1]);
	else
	{
		if (send_wrapper(client->socket, str, ft_strlen(str)))
		{
			if ((r = put_rights(client, fd)) == 1)
				r = put_init(client, fd);
		}
		if (r == 0)
			printf("\033[31mERROR\033[0m\nCouldn't put file \"%s\"\n", args[1]);
		else
			SUCCESS;
	}
	ft_array_free(args);
}
