/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 16:23:25 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:34:56 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		get_pwd(t_client *client)
{
	if (recv(client->socket, client->buff, BUF_SIZE, 0) < 0)
		printf("Receive error.\n");
	else
	{
		client->s_pwd = ft_strdup(client->buff);
		ft_bzero(client->buff, BUF_SIZE);
	}
}
