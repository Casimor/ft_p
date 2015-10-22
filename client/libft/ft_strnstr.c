/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:45:14 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:32:14 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && n >= i)
	{
		if (!ft_strncmp(s1, s2, i))
			return ((char *)s1);
		++s1;
		--n;
	}
	return (0);
}
