/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:45:04 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:32:10 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = malloc(sizeof(char *) * (size + 1));
	if (str == 0)
		return (NULL);
	while (i != size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
