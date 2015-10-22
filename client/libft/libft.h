/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:49:31 by bchevali          #+#    #+#             */
/*   Updated: 2015/10/19 13:30:24 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define BUFF_SIZE 32

/*
** Macro
*/
# define NNB(x)		(x >= 0 ? x : -x)
# define SC(val)	ft_setcolor(val);
# define RC			ft_resetcolor();
# define B_HEX		"0123456789abcdef"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	char			select;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}					t_dlist;

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	void			*content;
	size_t			content_size;
}					t_tree;

/*
** Typedef
*/
typedef void		(*t_dlistf)(t_dlist *, void *);
typedef void		(*t_listf)(t_list *, void *);
typedef void		(*t_tabf)(char *, void *);
typedef int			(*t_cmp)(void *, size_t, void *, size_t);
typedef void		(*t_deleter)(void *, size_t);

/*
** Part 1
*/
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_strclr(char *s);
char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);

/*
** Lst
*/
void				ft_lstappend(t_list **alst, t_list *new_element);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_free_lst(t_list **list);
void				ft_lstpushback(t_list **begin, t_list *new);
size_t				ft_lstsize(t_list **list);
t_list				*ft_lstrev(t_list *lst);
void				ft_lst_foreach(t_list *list, t_listf f, void *data);

/*
** Fonctions supplementaires
*/
void				ft_setcolor(unsigned char color);
void				ft_resetcolor(void);
int					get_next_line(const int fd, char **line);
char				**ft_str_split(const char *s);
char				*ft_utoa(size_t n);
int					fill_split(const char *s, char **str, int *c);
char				*ft_itoa_base(size_t n, char *base);
size_t				ft_get_maxsize(t_dlist *dlist);
void				ft_free_tab(char **tab);
void				ft_tab_foreach(char **tab, t_tabf f, void *data);
int					ft_tablen(char **tab);
char				*ft_strunion(char **str_array, char c);
int					ignore_whitespace(char **line);
void				ft_array_free(char **array);

/*
** Lstd
*/
void				ft_lstd_add(t_dlist **alst, t_dlist *new);
t_dlist				*ft_lstd_new(const void *content, size_t content_size);
void				ft_lstd_pushback(t_dlist **begin, t_dlist *new);
void				ft_lstd_foreach(t_dlist *dlist, t_dlistf f, void *data);
size_t				ft_lstd_size(t_dlist *dlist);
void				ft_lstd_delone(t_dlist *alst, t_dlist **head);
void				ft_free_lstd(t_dlist **list);

/*
** Lstdnc
*/
void				ft_lstdnc_pushback(t_dlist **begin, t_dlist *new);
void				ft_free_lstdnc(t_dlist **list);
size_t				ft_lstdnc_size(t_dlist *list);
void				ft_lstdnc_del_last(t_dlist	**list);
void				ft_lstdnc_del_cur(t_dlist **list);

/*
** Tree
*/
t_tree				*ft_tree_new(void *content, size_t content_size);
void				ft_tree_insert(t_tree **root, t_tree *node, t_cmp cmp);
void				ft_tree_delet(t_tree **root, t_deleter del);
t_tree				*ft_tree_delone(t_tree **r, void *n, size_t s, t_cmp cmp);
t_tree				*ft_tree_find(t_tree *node, void *n, size_t s, t_cmp cmp);

#endif
