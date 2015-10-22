/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:41:22 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/20 15:13:13 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strequ("a", "a") -> 1
** ft_strequ("a", "b") -> 0
** ft_strequ(NULL, NULL) -> 1
** ft_strequ("a", NULL) -> 0
** ft_strequ(NULL, "a") -> 0
*/

int		ft_strequ(const char *s1, const char *s2)
{
	if (!s2 ^ !s1)
		return (0);
	else if (!s1 && !s2)
		return (1);
	return (!ft_strcmp(s1, s2));
}
