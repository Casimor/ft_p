/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:55:00 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:25:34 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_foreach(t_list *list, t_listf f, void *data)
{
	if (list)
	{
		while (list)
		{
			f(list, data);
			list = list->next;
		}
	}
}
