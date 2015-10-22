/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:59:20 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 17:33:06 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				index;
	char			*dest2;
	const char		*src2;
	char			c2;

	dest2 = dest;
	src2 = src;
	index = 0;
	c2 = c;
	while (n != 0)
	{
		dest2[index] = src2[index];
		if (src2[index] == c2)
			return (&dest2[++index]);
		index++;
		n--;
	}
	return (0);
}
