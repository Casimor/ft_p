/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:58:43 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 19:58:44 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *lst)
{
	t_list	*out;

	out = NULL;
	while (lst)
	{
		ft_lstadd(&out, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
	}
	return (out);
}
