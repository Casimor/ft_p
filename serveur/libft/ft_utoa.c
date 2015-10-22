/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:48:37 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 21:48:38 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*n_is_null(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (0);
}

char			*ft_utoa(size_t n)
{
	char			*str;
	size_t			i;
	size_t			j;
	size_t			n1;

	i = 0;
	n1 = n;
	while (n1 != 0)
	{
		n1 = n1 / 10;
		++i;
	}
	str = ft_memalloc(i + 1);
	j = i - 1;
	n_is_null(n, str);
	while (n != 0)
	{
		str[j--] = n % 10 + 48;
		n = n / 10;
	}
	str[i + 1] = '\0';
	return (str);
}
