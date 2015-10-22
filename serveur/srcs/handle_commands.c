/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 18:06:32 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:38:20 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		handle_commands(t_server *server, t_client *clients)
{
	int		i;

	i = 0;
	while (i < server->clients_nb)
	{
		if (clients[i].get != NONE)
			get_handle(&clients[i]);
		if (clients[i].put != NONE)
			put_handle(&clients[i]);
		++i;
	}
}
