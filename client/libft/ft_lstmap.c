/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 16:56:40 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 17:11:35 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*it;
	t_list	*mapped;
	t_list	*res;

	it = lst;
	mapped = 0;
	while (it)
	{
		res = f(it);
		ft_lstappend(&mapped, ft_lstnew(res->content, res->content_size));
		it = it->next;
	}
	return (mapped);
}
