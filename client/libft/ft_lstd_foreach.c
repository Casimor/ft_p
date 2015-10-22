/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:56:01 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:25:44 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_foreach(t_dlist *dlist, t_dlistf f, void *data)
{
	t_dlist	*tmp;

	if (dlist)
	{
		tmp = dlist;
		while (dlist->next != tmp)
		{
			f(dlist, data);
			dlist = dlist->next;
		}
		f(dlist, data);
	}
}
