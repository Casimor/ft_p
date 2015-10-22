#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/23 19:49:57 by bchevali          #+#    #+#              #
#    Updated: 2014/04/23 19:50:01 by bchevali         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=		libft.a

SRC 			=		ft_isalpha.c			\
						ft_memmove.c			\
						ft_putstr.c				\
						ft_strstr.c				\
						ft_isascii.c			\
						ft_memset.c				\
						ft_putstr_fd.c			\
						ft_tolower.c			\
						ft_isdigit.c			\
						ft_putchar.c			\
						ft_strcat.c				\
						ft_strlen.c				\
						ft_toupper.c			\
						ft_isprint.c			\
						ft_putchar_fd.c			\
						ft_strchr.c				\
						ft_strncat.c			\
						ft_strlcat.c			\
						ft_memccpy.c			\
						ft_putendl.c			\
						ft_strclr.c				\
						ft_strncmp.c			\
						ft_atoi.c				\
						ft_memchr.c				\
						ft_putendl_fd.c			\
						ft_strcmp.c				\
						ft_strncpy.c			\
						ft_bzero.c				\
						ft_memcmp.c				\
						ft_putnbr.c				\
						ft_strcpy.c				\
						ft_strnstr.c			\
						ft_isalnum.c			\
						ft_memcpy.c				\
						ft_putnbr_fd.c			\
						ft_strdup.c				\
						ft_strrchr.c			\
						ft_striteri.c			\
						ft_striter.c			\
						ft_memalloc.c			\
						ft_memdel.c				\
						ft_strnew.c				\
						ft_strdel.c				\
						ft_strmap.c				\
						ft_strmapi.c			\
						ft_itoa.c				\
						ft_strequ.c				\
						ft_strnequ.c			\
						ft_strsub.c				\
						ft_strjoin.c			\
						ft_strtrim.c			\
						ft_strsplit.c			\
						ft_lstappend.c 			\
						ft_lstdel.c				\
						ft_lstdelone.c			\
						ft_lstiter.c			\
						ft_lstmap.c				\
						ft_lstadd.c				\
						ft_lstnew.c				\
						ft_setcolor.c			\
						ft_resetcolor.c			\
						get_next_line.c			\
						ft_lstpushback.c		\
						ft_lstrev.c				\
						ft_lstsize.c			\
						ft_str_split.c			\
						ft_utoa.c				\
						split_tools.c			\
						ft_itoa_base.c			\
						ft_lstd_add.c			\
						ft_lstd_new.c			\
						ft_lstd_pushback.c		\
						ft_lstd_foreach.c		\
						ft_lstd_size.c			\
						ft_lstd_delone.c		\
						ft_get_maxsize.c		\
						ft_lst_foreach.c		\
						ft_free_lst.c			\
						ft_free_tab.c			\
						ft_tab_foreach.c		\
						ft_tree_insert.c		\
						ft_tree_new.c			\
						ft_tree_delet.c			\
						ft_tree_delone.c		\
						ft_tree_find.c			\
						ft_tablen.c				\
						ft_strunion.c			\
						ignore_whitespace.c		\
						ft_free_lstd.c			\
						ft_lstdnc_pushback.c	\
						ft_free_lstdnc.c		\
						ft_lstdnc_size.c		\
						ft_lstdnc_del_last.c	\
						ft_lstdnc_del_cur.c 	\
						ft_array_free.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\n\033[34m[Linking: $(NAME)]\033[0m"
		@ar ru $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\033[32m[Done: $(NAME)]\033[0m"

$(OBJ): $(SRC)
		@echo "\n\033[36m[Compiling: $(NAME)]\033[0m"
		@gcc -c $(SRC) $(FLAGS) libft.h

clean:
		@echo "\n\033[35m[Cleaning: $(NAME)]\033[0m"
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
