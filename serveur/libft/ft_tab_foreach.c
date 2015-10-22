/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:47:49 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 21:47:50 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tab_foreach(char **tab, t_tabf f, void *data)
{
	size_t	c;

	c = 0;
	while (tab[c])
	{
		f(tab[c], data);
		++c;
	}
}
