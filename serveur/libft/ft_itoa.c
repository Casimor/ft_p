/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:54:36 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:25:28 by bchevali         ###   ########.fr       */
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

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				j;
	long int		n1;
	long int		n2;

	n1 = NNB(n);
	n2 = n;
	n2 = NNB(n2);
	i = 0;
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / 10;
	n >= 0 ? i : (i = i + 1);
	str = ft_memalloc(i + 1);
	j = i - 1;
	ft_if_n_is_null(n, str);
	while (n2 != 0)
	{
		str[j--] = n2 % 10 + 48;
		n2 = n2 / 10;
	}
	str[i + 1] = '\0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
