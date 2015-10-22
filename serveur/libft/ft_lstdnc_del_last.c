/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnc_del_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:57:38 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:26:56 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdnc_del_last(t_dlist **list)
{
	t_dlist	*it;
	t_dlist	*tmp;

	if (list)
	{
		it = *list;
		while (it->next)
			it = it->next;
		if (it->previous)
		{
			tmp = it->previous;
			tmp->next = NULL;
			free(it);
		}
		else
		{
			free(*list);
			*list = NULL;
		}
		free(it->content);
	}
}
