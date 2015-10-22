/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:47:14 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:32:32 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		j;
	int		c;

	i = ft_strlen(s);
	str = ft_memalloc(i + 1);
	j = 0;
	c = 0;
	i--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	if (s[j] == '\0')
		return (ft_strnew(0));
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	while (j != (i + 1))
	{
		str[c] = s[j];
		j++;
		c++;
	}
	str[c] = '\0';
	return (str);
}
