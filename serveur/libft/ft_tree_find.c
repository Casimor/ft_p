/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:48:25 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:32:59 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_tree_find(t_tree *node, void *n, size_t s, t_cmp cmp)
{
	int	cmp_value;

	if (node)
	{
		cmp_value = cmp(node->content, node->content_size, n, s);
		if (!cmp_value)
			return (node);
		if (cmp_value > 0)
			return (ft_tree_find(node->right, n, s, cmp));
		return (ft_tree_find(node->left, n, s, cmp));
	}
	return (0);
}
