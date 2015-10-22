/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnc_pushback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:57:48 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:27:00 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdnc_pushback(t_dlist **begin, t_dlist *new)
{
	t_dlist	*tmp;

	if (begin)
	{
		if (*begin)
		{
			tmp = *begin;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->next = NULL;
			new->previous = tmp;
		}
		else
		{
			new->next = NULL;
			new->previous = NULL;
			*begin = new;
		}
	}
}
