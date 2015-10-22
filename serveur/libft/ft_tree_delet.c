/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_delet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:08:38 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 18:08:42 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tree(t_tree *top, t_deleter del)
{
	if (top)
	{
		free_tree(top->left, del);
		free_tree(top->right, del);
		del(top->content, top->content_size);
		free(top);
	}
}

void		ft_tree_delet(t_tree **root, t_deleter del)
{
	t_tree	*top;

	top = *root;
	if (top)
	{
		free_tree(top, del);
		*root = 0;
	}
}
