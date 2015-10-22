/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:58:29 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 19:58:29 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
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
	}
	return (new_elem);
}
