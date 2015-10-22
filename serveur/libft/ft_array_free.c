/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 13:27:52 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/19 15:45:34 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_array_free(char **array)
{
	char	**save;

	save = array;
	while (*array)
	{
		free(*array);
		++array;
	}
	free(save);
}
