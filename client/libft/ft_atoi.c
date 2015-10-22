/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:50:12 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:23:45 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_atoi_ignored(char c)
{
	return (c == '\n'
	|| c == '\v'
	|| c == '\t'
	|| c == '\r'
	|| c == '\f'
	|| c == ' ');
}

int			ft_atoi(const char *str)
{
	int		c;
	int		i;

	c = 0;
	i = 0;
	if (str == '\0')
		return (0);
	while (is_atoi_ignored(*str))
		++str;
	if (str[0] == '-' || str[0] == '+')
		c = 1;
	while (str[c] != '\0' && (str[c] >= '0' && str[c] <= '9'))
	{
		i = i * 10 + str[c] - '0';
		c = c + 1;
	}
	if (str[0] == '-')
		return (-i);
	return (i);
}
