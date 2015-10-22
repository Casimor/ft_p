/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_whitespace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:49:02 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:33:12 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ignore_whitespace(char **line)
{
	while (**line == ' ' || **line == '\t')
		++(*line);
	if (**line == '\0')
		return (0);
	return (1);
}
