/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 11:53:51 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 15:25:29 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void			go_pwd(t_client *client)
{
	if (!client->pwd)
		chdir(client->home);
	else
		chdir(client->pwd);
}

void			get_home(t_info *data)
{
	char	buf[BUF_SIZE];

	ft_bzero(buf, BUF_SIZE);
	getcwd(buf, BUF_SIZE);
	data->home = ft_strdup(buf);
	ft_bzero(buf, BUF_SIZE);
}

static void		check_path(char *path, t_client *client, t_info *data)
{
	if (!chdir(path))
	{
		client->old_pwd = ft_strdup(data->buf);
		getcwd(client->write_buf, BUF_SIZE);
		if (ft_strncmp(data->home, client->write_buf, ft_strlen(data->home)))
		{
			cd_error(client, data, "error1");
			return ;
		}
		client->to_send = ft_strlen(client->write_buf);
		client->pwd = ft_strdup(client->write_buf);
		ft_bzero(data->buf, BUF_SIZE);
		return ;
	}
	cd_error(client, data, "error2");
}

void			cd_command(t_client *client, char **args, t_info *data)
{
	char	*path;

	ft_bzero(data->buf, BUF_SIZE);
	go_pwd(client);
	if (!args[1])
		go_home(data, client);
	else if (cd_opt(args[1], data, client))
	{
		getcwd(data->buf, BUF_SIZE);
		path = ft_strjoin(data->buf, "/");
		path = ft_strjoin(path, args[1]);
		check_path(path, client, data);
		free(path);
	}
}
