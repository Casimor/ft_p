/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:59:47 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:27:41 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*str;
	const char		*str2;

	str = dest;
	str2 = src;
	i = 0;
	while (n != i)
	{
		str[i] = str2[i];
		i++;
	}
	return (str);
}
