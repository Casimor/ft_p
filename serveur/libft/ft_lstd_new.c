/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:56:17 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 19:56:18 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_lstd_new(const void *content, size_t content_size)
{
	t_dlist	*new_elem;

	new_elem = malloc(sizeof(t_dlist));
	if (new_elem)
	{
		if (content != 0)
		{
			new_elem->content = ft_memalloc(content_size);
			ft_memcpy(new_elem->content, content, content_size);
			new_elem->content_size = content_size;
		}
		else
		{
			new_elem->content = NULL;
			new_elem->content_size = 0;
		}
		new_elem->next = NULL;
		new_elem->previous = NULL;
		new_elem->select = 1;
	}
	return (new_elem);
}
