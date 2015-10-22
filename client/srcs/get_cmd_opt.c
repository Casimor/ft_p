/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 16:51:03 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/19 18:24:59 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	get_answer(void)
{
	char				*line;

	line = NULL;
	ft_putstr("file already exist. Do you want to overwrite ? (Y/n) : ");
	get_next_line(0, &line);
	if (!ft_strcmp(line, "Y") || !ft_strcmp(line, "y"))
	{
		free(line);
		return (0);
	}
	SUCCESS;
	return (1);
}

static int	check_dir(char *name)
{
	DIR			*dir;
	t_dirent	*dirent;
	int			i;

	i = 0;
	if (!(dir = opendir(".")))
		printf("Error open .\n");
	while ((dirent = readdir(dir)))
	{
		if (!ft_strcmp(name, dirent->d_name))
		{
			free(name);
			if (dirent->d_type == 4)
			{
				ERROR;
				printf("A directory already called \"%s\".\n", dirent->d_name);
				return (1);
			}
			return (get_answer());
		}
	}
	free(name);
	return (0);
}

int			file_exist(char *name)
{
	char				*n_file;
	int					i;
	int					j;

	n_file = NULL;
	i = ft_strlen(name);
	j = i;
	while (name[i] != '/' && i > 0)
		i--;
	if (name[i] == '/')
		i++;
	n_file = ft_strsub(name, i, j);
	return (check_dir(n_file));
}
