/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnc_del_cur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:57:30 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:26:52 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdnc_del_cur(t_dlist **list)
{
	t_dlist		*tmp_previous;
	t_dlist		*tmp_next;

	tmp_previous = NULL;
	tmp_next = (*list)->next;
	if ((*list)->previous)
	{
		tmp_previous = (*list)->previous;
		tmp_previous->next = tmp_next;
	}
	free((*list)->content);
	free(*list);
	tmp_next->previous = tmp_previous;
}
