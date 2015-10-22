/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:54:48 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:25:31 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_if_n_is_null(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (0);
}

char			*ft_itoa_base(size_t n, char *base)
{
	char			*str;
	int				i;
	int				j;
	long int		n1;
	int				b;

	n1 = n;
	i = 0;
	b = ft_strlen(base);
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / b;
	str = ft_memalloc(i + 1);
	j = i - 1;
	ft_if_n_is_null(n, str);
	while (n != 0)
	{
		str[j--] = base[n % b];
		n = n / b;
	}
	str[i + 1] = '\0';
	return (str);
}
