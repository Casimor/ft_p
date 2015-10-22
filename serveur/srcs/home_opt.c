/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 17:28:07 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/19 15:49:56 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void		abs_path(char *path)
{
	if (chdir(path))
	{
		printf("the path is not correct.\n");
		printf("Current directory become the home.\n");
	}
}

static void		rel_path(char *path)
{
	char	buf[BUF_SIZE];
	char	*path_abs;

	ft_bzero(buf, BUF_SIZE);
	getcwd(buf, BUF_SIZE);
	path_abs = ft_strjoin(buf, "/");
	path_abs = ft_strjoin(path_abs, path);
	if (chdir(path_abs))
	{
		printf("the path is not correct.\n");
		printf("Current directory become the home.\n");
	}
	free(path_abs);
}

void			init_home(char *home)
{
	if (home[0] == '/')
		abs_path(home);
	else
		rel_path(home);
}
