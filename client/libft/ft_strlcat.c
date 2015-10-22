/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:42:23 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:31:43 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	c;
	unsigned int	i;

	i = ft_strlen(src);
	c = ft_strlen(dest);
	if (c >= size)
		return (size + i);
	ft_strncat(dest + c, src, size - c - 1);
	return (c + i);
}
