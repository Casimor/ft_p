/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:58:51 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:27:14 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list **list)
{
	t_list	*tmp;
	size_t	size;

	size = 0;
	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		++size;
	}
	return (size);
}
