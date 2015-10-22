/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 18:06:50 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/22 14:37:35 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <netinet/in.h>

# define MAX_CLIENTS 42
# define BUF_SIZE 1024

typedef struct sockaddr_in		t_sock;
typedef struct sockaddr			t_saddr;
typedef struct s_server			t_server;
typedef struct s_client			t_client;
typedef struct s_command		t_command;
typedef struct s_info			t_info;
typedef struct s_cd				t_cd;
typedef struct stat				t_stat;
typedef struct s_cmd			t_cmd;

struct		s_server
{
	int		socket;
	int		clients_nb;
	fd_set	read_fds;
	fd_set	write_fds;
};

struct		s_client
{
	char	*home;
	char	*pwd;
	char	*old_pwd;
	int		socket;
	char	name[BUF_SIZE];
	char	read_buf[BUF_SIZE];
	char	write_buf[BUF_SIZE];
	int		to_send;
	int		received;
	int		synchro;
	int		get;
	int		put;
	int		fd;
	char	*file;
};

struct		s_command
{
	char	*command;
	void	(*f)(t_client *, char **, t_info *);
};

struct		s_cmd
{
	char	*command;
	void	(*f)(char **, t_server *);
};

struct		s_cd
{
	char	*str;
	void	(*f)(t_info *, t_client *);
};

struct		s_info
{
	char	buf[BUF_SIZE];
	char	*home;
};

enum		e_state
{
	NONE,
	ANSWER,
	INIT,
	READY
};

/*
** Run server
*/
void		run(char **av);

/*
** Server setup
*/
int			init_server(char *port);
void		init_home(char *home);
/*
** Client handling
*/
void		client_connection(t_server *server, t_client *clients,
									t_info *data);
void		client_disconnection(t_server *server, t_client *clients,
									int current);

/*
** Message handling
*/
void		read_message(t_client *client);
void		send_message(t_client *client);
void		handle_message(t_client *client, t_info *data);

/*
** Commands handling
*/
void		ls_command(t_client *client, char **args, t_info *data);
void		pwd_command(t_client *client, char **args, t_info *data);
void		cd_command(t_client *client, char **args, t_info *data);
void		get_command(t_client *client, char **args, t_info *data);
void		put_command(t_client *client, char **args, t_info *data);
void		handle_commands(t_server *server, t_client *clients);

/*
** File handling
*/
void		get_handle(t_client *client);
void		put_handle(t_client *client);

/*
** Cd
*/
void		get_home(t_info *data);
void		go_pwd(t_client *client);
void		go_old(t_info *data, t_client *client);
void		go_home(t_info *data, t_client *client);
int			cd_opt(char	*opt, t_info *data, t_client *client);
void		cd_error(t_client *client, t_info *data, char *error);

/*
** Stdin commands
*/
void		check_stdin(t_server *server);
void		help_command(char **args, t_server *server);
void		quit_command(char **args, t_server *server);

#endif
