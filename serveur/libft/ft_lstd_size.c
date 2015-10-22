/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:56:54 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:25:57 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstd_count(t_dlist *dlist, void *data)
{
	size_t	*c;

	(void)*dlist;
	c = (size_t *)data;
	++(*c);
}

size_t		ft_lstd_size(t_dlist *dlist)
{
	size_t	c;

	c = 0;
	ft_lstd_foreach(dlist, ft_lstd_count, &c);
	return (c);
}
