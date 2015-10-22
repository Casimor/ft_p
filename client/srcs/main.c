/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 15:02:40 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/15 16:27:33 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void		usage(char *str)
{
	printf("usage: %s <addr> <port> (O) <directory home>\n", str);
}

int				main(int ac, char **av)
{
	if (ac < 3 || ac > 4)
		usage(av[0]);
	else
		run(av);
	return (0);
}
