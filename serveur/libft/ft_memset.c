/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 20:00:13 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:27:58 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	i;
	unsigned int	j;
	unsigned char	*str;

	j = 0;
	i = c;
	str = s;
	while (j < n)
	{
		str[j] = i;
		j++;
	}
	return (str);
}
