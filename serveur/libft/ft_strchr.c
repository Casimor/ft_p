/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:40:14 by bchevali          #+#    #+#             */
/*   Updated: 2015/06/11 18:05:51 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char*)&s[i]);
	return (NULL);
}
