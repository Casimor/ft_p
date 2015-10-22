/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 13:42:33 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/15 15:05:56 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static char		*split_pwd(char *pwd)
{
	char		**split;
	char		*str;
	int			i;

	i = 0;
	str = 0;
	split = ft_strsplit(pwd, '/');
	while (split[i])
		++i;
	if (i >= 2)
	{
		i -= 2;
		str = ft_strjoin(split[i], "/");
		str = ft_strjoin(str, split[i + 1]);
		ft_array_free(split);
		return (str);
	}
	return (split[0]);
}

void			prompt(t_client *client)
{
	char		*str;

	str = split_pwd(client->s_pwd);
	if (!client->user)
	{
		ft_putstr(str);
		write(1, " | Anonymous", 12);
		write(1, PROMPT, ft_strlen(PROMPT));
	}
	else
	{
		ft_putstr(str);
		write(1, " | ", 3);
		ft_putstr(client->user);
		write(1, PROMPT, ft_strlen(PROMPT));
	}
}
