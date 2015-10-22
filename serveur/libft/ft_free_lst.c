/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:51:40 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 19:51:42 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lst(t_list **list)
{
	t_list	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			free((*list)->content);
			free(*list);
			*list = tmp;
		}
		*list = NULL;
	}
}
