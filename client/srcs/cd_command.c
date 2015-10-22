/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 16:32:01 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 16:16:37 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			cd_command(char *str, t_client *client)
{
	ft_bzero(client->buff, BUF_SIZE);
	if (send(client->socket, str, ft_strlen(str), 0) < 0)
	{
		ERROR;
		printf("Send error.\n");
		return ;
	}
	recv(client->socket, client->buff, BUF_SIZE, 0);
	if (!ft_strncmp(client->buff, "error", 5))
		cd_error(client->buff, str);
	else
	{
		SUCCESS;
		client->s_pwd = ft_strdup(client->buff);
	}
}

static void		check_path(char *path, t_client *client, char *av)
{
	if (!chdir(path))
	{
		client->c_old_pwd = ft_strdup(client->buff);
		ft_bzero(client->buff, BUF_SIZE);
		getcwd(client->buff, BUF_SIZE);
		client->c_pwd = ft_strdup(client->buff);
		ft_bzero(client->buff, BUF_SIZE);
		SUCCESS;
		return ;
	}
	ERROR;
	printf("cd: no such file or directory: %s\n", av);
}

void			lcd_command(char *str, t_client *client)
{
	char	*path;
	char	**av;

	av = ft_strsplit(str, ' ');
	ft_bzero(client->buff, BUF_SIZE);
	if (!av[1])
		go_home(client);
	else if (cd_opt(av[1], client))
	{
		getcwd(client->buff, BUF_SIZE);
		path = ft_strjoin(client->buff, "/");
		path = ft_strjoin(path, av[1]);
		check_path(path, client, av[1]);
		free(path);
		ft_array_free(av);
	}
}
