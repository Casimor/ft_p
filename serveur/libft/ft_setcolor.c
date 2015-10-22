/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 20:03:32 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/18 15:30:23 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setcolor(unsigned char color)
{
	char	*color_str;

	color_str = ft_itoa(color);
	ft_putstr("\033[38;5;");
	ft_putstr(color_str);
	ft_putchar('m');
	free(color_str);
}
