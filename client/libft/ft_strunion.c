/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:47:40 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 21:47:41 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_unionsize(char **str_array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str_array[i])
		j = j + ft_strlen(str_array[i++]);
	return (j + i - 1);
}

char			*ft_strunion(char **str_array, char c)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	str = malloc(sizeof(*str) * (ft_unionsize(str_array) + 1));
	while (str_array[i])
	{
		ft_strcpy(str + j, str_array[i]);
		j = j + ft_strlen(str_array[i]);
		if (str_array[i + 1])
			str[j++] = c;
		i++;
	}
	str[j] = '\0';
	return (str);
}
