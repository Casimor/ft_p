/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:56:27 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 19:56:27 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_pushback(t_dlist **begin, t_dlist *new)
{
	t_dlist	*tmp;

	if (begin)
	{
		if (*begin)
		{
			tmp = *begin;
			while (tmp->next != *begin)
				tmp = tmp->next;
			tmp->next = new;
			(*begin)->previous = new;
			new->next = *begin;
			new->previous = tmp;
		}
		else
		{
			new->next = new;
			new->previous = new;
			*begin = new;
		}
	}
}
