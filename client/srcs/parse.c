/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 15:21:16 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 17:09:48 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static const t_command		g_commands[] = {
	{"cd", cd_command},
	{"ls", ls_command},
	{"get", get_command},
	{"put", put_command},
	{"pwd", pwd_command},
	{"lls", lls_command},
	{"lpwd", lpwd_command},
	{"lcd", lcd_command}
};

int				check_cmd(char *command)
{
	size_t		i;

	i = 0;
	while (i < sizeof(g_commands) / sizeof(t_command))
	{
		if (!ft_strcmp(g_commands[i].command, command))
			return (0);
		++i;
	}
	return (1);
}

static void		exe_cmd(char **cmd, char *line, t_client *client)
{
	size_t		i;

	i = 0;
	while (i < sizeof(g_commands) / sizeof(t_command))
	{
		if (!ft_strcmp(g_commands[i].command, cmd[0]))
		{
			ft_bzero(client->buff, BUF_SIZE);
			g_commands[i].f(line, client);
			ft_bzero(client->buff, BUF_SIZE);
			return ;
		}
		++i;
	}
}

int				parse(char *line, t_client *client)
{
	char		**cmd;
	int			i;

	i = 0;
	line = ft_strtrim(line);
	cmd = ft_strsplit(line, ' ');
	if (!ft_strcmp(line, "quit"))
	{
		quit_command(client->socket);
		ft_array_free(cmd);
	}
	if (!check_cmd(cmd[0]))
	{
		exe_cmd(cmd, line, client);
		ft_array_free(cmd);
		free(line);
		return (0);
	}
	if (!ft_strcmp(line, "help"))
		i = help_command();
	if (!i)
		printf("Command not found.\n");
	ft_array_free(cmd);
	free(line);
	return (1);
}
