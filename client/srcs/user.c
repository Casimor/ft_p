/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 15:05:15 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/13 13:39:24 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char		*get_user(int socket)
{
	char	*line;

	line = 0;
	ft_putstr("User: ");
	get_next_line(0, &line);
	line = ft_strtrim(line);
	if (ft_strlen(line) == 0)
		line = ft_strdup("Anonymous");
	send_wrapper(socket, line, ft_strlen(line));
	return (line);
}
