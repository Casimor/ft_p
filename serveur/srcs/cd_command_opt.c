/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 12:13:28 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/19 17:57:50 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static const t_cd	g_cd_cmd[] =
{
	{"~", go_home},
	{"-", go_old}
};

void		go_home(t_info *data, t_client *client)
{
	chdir(data->home);
	ft_strcpy(client->write_buf, data->home);
	client->to_send = ft_strlen(client->write_buf);
}

void		go_old(t_info *data, t_client *client)
{
	ft_bzero(data->buf, BUF_SIZE);
	getcwd(data->buf, BUF_SIZE);
	if (!chdir(client->old_pwd))
	{
		ft_strcpy(client->write_buf, client->old_pwd);
		client->to_send = ft_strlen(client->write_buf);
		free(client->old_pwd);
		client->pwd = ft_strdup(client->old_pwd);
		client->old_pwd = ft_strdup(data->buf);
		ft_bzero(data->buf, BUF_SIZE);
		return ;
	}
	else
	{
		ft_strcpy(client->write_buf, client->home);
		client->to_send = ft_strlen(client->write_buf);
		ft_bzero(data->buf, BUF_SIZE);
	}
}

int			cd_opt(char *opt, t_info *data, t_client *client)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_cd_cmd) / sizeof(t_cd))
	{
		if (!ft_strcmp(g_cd_cmd[i].str, opt))
		{
			g_cd_cmd[i].f(data, client);
			return (0);
		}
		i++;
	}
	return (1);
}
