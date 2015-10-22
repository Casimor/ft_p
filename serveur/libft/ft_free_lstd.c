/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lstd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:52:04 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 19:52:06 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lstd(t_dlist **list)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	if (list)
	{
		tmp = *list;
		while (tmp->next && tmp->next != *list)
		{
			tmp2 = tmp->next;
			free(tmp->content);
			free(tmp);
			tmp = tmp2;
		}
		free(tmp->content);
		free(tmp);
		*list = NULL;
	}
}
