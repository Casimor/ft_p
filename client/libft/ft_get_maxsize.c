/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maxsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:52:55 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:24:36 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_maxsize(t_dlist *dlist, void *data)
{
	size_t	*c;

	c = (size_t *)data;
	if (dlist->content_size > *c)
		*c = dlist->content_size;
}

size_t		ft_get_maxsize(t_dlist *dlist)
{
	size_t	c;

	c = 0;
	ft_lstd_foreach(dlist, ft_maxsize, &c);
	return (c);
}
