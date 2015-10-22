/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:39:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/04/22 16:16:39 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_tab_memalloc(size_t size)
{
	char		**str;

	str = (char**)malloc(sizeof(char*) * (size + 1));
	if (str == 0)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

static int		ft_count(const char *s)
{
	int			c1;
	int			c2;

	c1 = 0;
	c2 = 0;
	while (s[c1])
	{
		while (ft_isdigit(s[c1]) == 0 && s[c1] != '-' && s[c1] != '+'
				&& s[c1] != '\0')
			c1++;
		if (s[c1] != '\0')
			c2++;
		while (((ft_isdigit(s[c1]) || s[c1] == '-') || s[c1] == '+')
				&& s[c1] != '\0')
			c1++;
	}
	return (c2);
}

static int		next_valid(const char *s, int c)
{
	while (ft_isdigit(s[c]) == 0 && s[c] != '-' && s[c] != '+' && s[c] != '\0')
		++c;
	if (ft_isdigit(s[c]))
		return (c);
	else if (s[c] == '-' || s[c] == '+')
	{
		while ((s[c] == '-' || s[c] == '+') && s[c] != '\0')
			c++;
	}
	if (s[c] == '\0')
		return (c);
	return (c - 1);
}

static int		ignore(const char *s, int c)
{
	while (((s[c] == '-' || s[c] == '+') || ft_isdigit(s[c])) && s[c] != '\0')
		c++;
	return (c);
}

char			**ft_str_split(const char *s)
{
	char		**str;
	int			c[4];

	c[0] = ft_count(s);
	c[1] = 0;
	c[2] = 0;
	c[3] = 0;
	str = ft_tab_memalloc(c[0] + 1);
	while (s[c[2]])
	{
		c[3] = next_valid(s, c[2]);
		c[2] = c[3];
		if (s[c[2]] == '-' || s[c[2]] == '+')
			c[2]++;
		while (ft_isdigit(s[c[2]]) && s[c[2]] != '\0')
			c[2]++;
		if (c[1] != c[0])
			c[1] = fill_split(s, str, c);
		c[2] = ignore(s, c[2]);
	}
	str[c[1]] = ft_memalloc(1);
	str[c[1]][0] = '\0';
	return (str);
}
