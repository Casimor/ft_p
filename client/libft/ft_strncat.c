/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:43:01 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:31:57 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	c;
	unsigned int	c2;

	c = 0;
	c2 = 0;
	while (dest[c] != '\0')
		c++;
	while (src[c2] != '\0' && c2 < n)
	{
		dest[c] = src[c2];
		c++;
		c2++;
	}
	dest[c] = '\0';
	return (dest);
}
