/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 15:06:25 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/19 15:44:31 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <dirent.h>

# define PROMPT					" ✗ "
# define BUF_SIZE				1024
# define SUCCESS				printf("\033[32mSUCCESS\033[0m\n");
# define ERROR					printf("\033[31mERROR\033[0m\n");

typedef struct sockaddr_in		t_sock;
typedef struct sockaddr			t_saddr;
typedef struct protoent			t_proto;
typedef struct s_client			t_client;
typedef struct s_command		t_command;
typedef struct stat				t_stat;
typedef struct s_cd				t_cd;
typedef struct dirent			t_dirent;

struct			s_client
{
	int			socket;
	char		*user;
	char		*home;
	char		*s_pwd;
	char		*c_pwd;
	char		*c_old_pwd;
	char		buff[BUF_SIZE];
};

struct			s_command
{
	char		*command;
	void		(*f)(char *cmd, t_client *client);
};

struct			s_cd
{
	char		*str;
	void		(*f)(t_client *);
};

/*
** Run client
*/
void			run(char **args);

/*
** Prompt
*/
void			prompt(t_client *client);
char			*get_user(int sock);
void			get_pwd(t_client *client);

/*
** Wrapper
*/
int				send_wrapper(int socket, char *buffer, int to_send);
int				recv_wrapper(t_client *client);

/*
** Commands
*/
int				parse(char *str, t_client *client);
int				check_cmd(char *cmd);
int				help_command(void);
void			quit_command(int socket);
void			cd_command(char *cmd, t_client *client);
void			ls_command(char *cmd, t_client *client);
void			pwd_command(char *cmd, t_client *client);
void			get_command(char *cmd, t_client *client);
void			put_command(char *cmd, t_client *client);
void			lls_command(char *cmd, t_client *client);
void			lpwd_command(char *cmd, t_client *client);
void			lcd_command(char *cmd, t_client *client);
int				file_exist(char *name);

/*
** Lcd + home functions
*/
void			init_home(char *home);
void			get_home(t_client *client);
void			go_home(t_client *client);
void			go_old(t_client *client);
int				cd_opt(char	*opt, t_client *client);

/*
** Client
*/
void			init_client(t_client *client, char **av);

/*
** Error
*/
int				error_cmd(char *str, char *name_cmd);
void			cd_error(char *error, char *str);

#endif
