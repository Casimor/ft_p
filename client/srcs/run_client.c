/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 14:09:06 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:35:40 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			run(char **args)
{
	t_client	client;
	char		*line;

	line = NULL;
	if (args[3])
		init_home(args[3]);
	get_home(&client);
	init_client(&client, args);
	if (client.socket > 0)
	{
		get_pwd(&client);
		prompt(&client);
		while ((get_next_line(0, &line) == 1))
		{
			if (ft_strlen(line) > 0)
				parse(line, &client);
			prompt(&client);
		}
		close(client.socket);
		free(client.user);
		free(client.s_pwd);
	}
}
