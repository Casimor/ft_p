/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:57:09 by bchevali          #+#    #+#             */
/*   Updated: 2014/04/23 19:57:10 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*i;
	t_list	*tmp;

	if (alst)
	{
		i = *alst;
		while (i)
		{
			del(i->content, i->content_size);
			tmp = i->next;
			free(i);
			i = tmp;
		}
		*alst = NULL;
	}
}
