/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 12:08:14 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/19 15:50:16 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void			cd_error(t_client *client, t_info *data, char *error)
{
	if (!ft_strcmp(error, "error1"))
	{
		chdir(data->buf);
		ft_bzero(client->write_buf, ft_strlen(client->write_buf));
		ft_strcpy(client->write_buf, error);
		client->to_send = ft_strlen(client->write_buf);
		ft_bzero(data->buf, BUF_SIZE);
	}
	else if (!ft_strcmp(error, "error2"))
	{
		ft_strcpy(client->write_buf, error);
		client->to_send = ft_strlen(client->write_buf);
		ft_bzero(data->buf, BUF_SIZE);
	}
}
