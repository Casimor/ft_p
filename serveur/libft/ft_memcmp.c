/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 15:34:55 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:35:00 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	const char		*str1;
	const char		*str2;
	unsigned int	index;

	index = 0;
	str1 = s1;
	str2 = s2;
	while (index < n)
	{
		if (str1[index] == str2[index])
			index++;
		else
			return ((unsigned char)str1[index] - (unsigned char)str2[index]);
	}
	return (0);
}
