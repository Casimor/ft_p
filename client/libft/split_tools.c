/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:49:10 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 18:12:06 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*strnew_zero(void)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

int			split_tools(const char *s, char **str, int *c)
{
	if (s[c[2] - 1] == '+' || s[c[2] - 1] == '-')
		str[c[1]] = strnew_zero();
	else
		str[c[1]] = ft_strsub(s, c[3], (c[2] - c[3]));
	c[1]++;
	return (c[1]);
}
