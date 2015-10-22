/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 17:30:36 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:35:29 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			recv_wrapper(t_client *client)
{
	if (recv(client->socket, client->buff, BUF_SIZE, 0) < 0)
	{
		printf("Receive error.\n");
		return (0);
	}
	return (1);
}
