/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 15:09:37 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/19 15:54:42 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static const t_cmd		g_cmd[] = {
	{ "help", &help_command },
	{ "quit", &quit_command }
};

void	help_command(char **cmd, t_server *server)
{
	(void)server;
	if (!cmd[1])
	{
		printf("<-------------------------------------------------->\n");
		printf("| help : show commands                             |\n");
		printf("| quit : quit the program                          |\n");
		printf("<-------------------------------------------------->\n");
	}
}

void	quit_command(char **cmd, t_server *server)
{
	(void)cmd;
	close(server->socket);
	exit(0);
}

void	check_stdin(t_server *server)
{
	size_t		i;
	char		**args;
	char		*line;

	line = NULL;
	i = 0;
	get_next_line(0, &line);
	args = ft_strsplit(line, ' ');
	if (args[0])
	{
		while (i < sizeof(g_cmd) / sizeof(t_cmd))
		{
			if (!ft_strcmp(g_cmd[i].command, args[0]))
			{
				g_cmd[i].f(args, server);
				break ;
			}
			i++;
		}
	}
	ft_array_free(args);
}
