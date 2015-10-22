/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 11:39:19 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 16:18:04 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			help_command(void)
{
	printf("<--------------------------------------------------------->\n");
	printf(" ls : list directory contents\n");
	printf(" lls : list directory contents (local)\n");
	printf(" cd : change the working directory\n");
	printf(" lcd : change the working directory (local)\n");
	printf(" pwd : show the path of the working directory\n");
	printf(" lpwd : show the path of the working directory (local)\n");
	printf(" get _file_ : recuperate _file_ from the server\n");
	printf(" put _file_ : send the _file_ to the server\n");
	printf(" quit : quit the program\n");
	printf("<--------------------------------------------------------->\n");
	SUCCESS;
	return (1);
}

void		quit_command(int sock)
{
	SUCCESS;
	close(sock);
	exit(0);
}
