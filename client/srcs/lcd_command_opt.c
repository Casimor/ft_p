/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcd_command_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 15:26:20 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 17:31:26 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static const t_cd	g_cd_cmd[] =
{
	{"~", go_home},
	{"-", go_old}
};

void				go_home(t_client *client)
{
	chdir(client->home);
	SUCCESS;
}

void				go_old(t_client *client)
{
	ft_bzero(client->buff, BUF_SIZE);
	getcwd(client->buff, BUF_SIZE);
	if (!chdir(client->c_old_pwd))
	{
		free(client->c_old_pwd);
		client->c_old_pwd = ft_strdup(client->buff);
		ft_bzero(client->buff, BUF_SIZE);
	}
	SUCCESS;
}

int					cd_opt(char *opt, t_client *client)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_cd_cmd) / sizeof(t_cd))
	{
		if (!ft_strcmp(g_cd_cmd[i].str, opt))
		{
			g_cd_cmd[i].f(client);
			return (0);
		}
		i++;
	}
	return (1);
}
