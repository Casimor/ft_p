/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 20:00:03 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:27:54 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		index;
	char				*dest2;
	const char			*src2;
	char				*copy;

	index = 0;
	dest2 = dest;
	src2 = src;
	copy = ft_memalloc(n);
	while (index < n)
	{
		copy[index] = src2[index];
		index++;
	}
	index = 0;
	while (index < n)
	{
		dest2[index] = copy[index];
		index++;
	}
	free(copy);
	return (dest);
}
