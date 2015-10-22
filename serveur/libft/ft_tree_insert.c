/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:53:04 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 18:23:43 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	insert(t_tree *r, t_tree *n, t_cmp cmp)
{
	if (cmp(r->content, r->content_size, n->content, n->content_size) < 0)
	{
		if (!r->left)
			r->left = n;
		else
			insert(r->left, n, cmp);
	}
	else
	{
		if (!r->right)
			r->right = n;
		else
			insert(r->right, n, cmp);
	}
}

void		ft_tree_insert(t_tree **root, t_tree *node, t_cmp cmp)
{
	if (!*root)
		*root = node;
	else
		insert(*root, node, cmp);
}
