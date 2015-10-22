/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:46:59 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:32:25 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	size_t		i;

	i = ft_strlen(s2);
	while (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		if (!ft_strncmp(s1, s2, i))
			return ((char *)s1);
		++s1;
	}
	return (0);
}
