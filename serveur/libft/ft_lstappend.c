/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:01:11 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 17:09:59 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new_element)
{
	t_list	*it;

	if (!*alst)
		*alst = new_element;
	else
	{
		it = *alst;
		while (it->next)
			it = it->next;
		it->next = new_element;
	}
}
