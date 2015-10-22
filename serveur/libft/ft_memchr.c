/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:59:32 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 17:32:03 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	index;
	const char		*str;
	char			c2;

	index = 0;
	str = s;
	c2 = c;
	while (index < n)
	{
		if (str[index] == c2)
			return ((char *)&str[index]);
		index++;
	}
	return (0);
}
