/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnc_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:57:57 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:27:03 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstdnc_size(t_dlist *list)
{
	t_dlist	*tmp;
	size_t	c;

	c = 0;
	if (list)
	{
		tmp = list;
		while (tmp)
		{
			++c;
			tmp = tmp->next;
		}
	}
	return (c);
}
