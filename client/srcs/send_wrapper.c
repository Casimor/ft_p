/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 14:46:10 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:58:31 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			send_wrapper(int socket, char *buffer, int to_send)
{
	if (send(socket, buffer, to_send, 0) < 0)
	{
		printf("\033[31mERROR\033[0m\n");
		printf("Send error.\n");
		return (0);
	}
	return (1);
}
