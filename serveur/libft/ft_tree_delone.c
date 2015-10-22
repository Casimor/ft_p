/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:15:18 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 18:15:20 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rebuild_tree(t_tree *n, t_tree *rem, t_tree **s, t_cmp cmp)
{
	if (n)
	{
		if (n != rem)
			ft_tree_insert(s, n, cmp);
		rebuild_tree(n->left, rem, s, cmp);
		rebuild_tree(n->right, rem, s, cmp);
	}
}

t_tree		*ft_tree_delone(t_tree **r, void *n, size_t s, t_cmp cmp)
{
	t_tree	*removed;
	t_tree	*new_tree;

	new_tree = 0;
	removed = ft_tree_find(*r, n, s, cmp);
	rebuild_tree(*r, removed, &new_tree, cmp);
	*r = new_tree;
	return (removed);
}
