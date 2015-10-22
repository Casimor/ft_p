/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:19:47 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 18:19:50 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_tree_new(void *content, size_t content_size)
{
	t_tree	*new_elem;

	new_elem = malloc(sizeof(t_tree));
	if (new_elem)
	{
		new_elem->content_size = (content ? content_size : 0);
		new_elem->content = (content ? ft_memalloc(content_size) : 0);
		if (new_elem->content)
			ft_memcpy(new_elem->content, content, content_size);
		new_elem->right = NULL;
		new_elem->left = NULL;
	}
	return (new_elem);
}
