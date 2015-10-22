/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:45:47 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:32:18 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = c;
	i = 0;
	while (s[i])
		i++;
	while (i != 0)
	{
		if (s[i] == cc)
			return ((char*)&s[i]);
		i--;
	}
	if (s[i] == cc)
		return ((char*)&s[i]);
	return (NULL);
}
