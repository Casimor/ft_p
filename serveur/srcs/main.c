/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 17:40:56 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:39:03 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void		usage(char *str)
{
	printf("usage: %s <port> (O) <directory home>\n", str);
}

int				main(int ac, char **av)
{
	if (ac < 2)
		usage(av[0]);
	else
		run(av);
	return (0);
}
